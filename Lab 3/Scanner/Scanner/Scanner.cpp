#include "Scanner.h"

Scanner::Scanner(const std::string& token_file_path) : program_position{ 0 }, current_line{ 0 }, identifier_automata(FA_IDENTIFIER_FILE_PATH), int_constant_automata(FA_INT_CONSTANT_FILE_PATH), char_constant_automata(FA_CHAR_CONSTANT_FILE_PATH), string_constant_automata(FA_STRING_CONSTANT_FILE_PATH) {
    this->readTokenFile(token_file_path);
}

void Scanner::readTokenFile(const std::string& token_file_path) {
    std::ifstream token_file(token_file_path);
    if (!token_file.is_open()) {
        throw std::runtime_error("Unable to open token file at " + token_file_path);
    }

    std::string line;
    size_t index = 0;
    while (std::getline(token_file, line)) {
        if (line.empty()) { continue;}
        this->reserved_tokens.add(line, ++index);
    }

    if (!token_file.eof()) {
        throw std::runtime_error("I/O Error occurred while reading the token file.");
    }

    std::cout << "Finished reading reserved tokens from '" << token_file_path << "'\n";
}

void Scanner::readProgramFile(const std::string& program_file_path) {
    std::ifstream program_file(program_file_path);
    if (!program_file.is_open()) {
        throw std::runtime_error("Unable to open program file at " + program_file_path);
    }

    char c;
    while (program_file >> std::noskipws >> c) {
        this->program.push_back(c);
    }

    if (!program_file.eof()) {
        throw std::runtime_error("I/O Error occurred while reading the program file.");
    }

    std::cout << "Finished reading program from '" << program_file_path << "'\n";
}

void Scanner::scan(const std::string& program_file_path) {
    this->readProgramFile(program_file_path);
    this->program_position = 0;
    this->current_line = 1;

    try {
        this->parse();
    }
    catch (const std::runtime_error& e)
    {
        throw std::runtime_error("Lexical error on line " + std::to_string(this->current_line) + ": " + e.what() + "\n");
    }

    std::cout << "Finished scanning file '" << program_file_path << "'\n";
}

void Scanner::parse() {
    std::optional<std::string> next_token;

    while (this->program_position < this->program.size()) {
        // Detect token
        next_token = this->nextToken();

        // Classify and codify token
        if (next_token.has_value()) {           // Whitespaces and comments are not classified
            this->classifyToken(*next_token);
        }
    }
}

std::optional<std::string> Scanner::nextToken() {
    // Skip whitespaces and line separators
    this->handleWhitespaceAndLineSeparator();

    if (this->program_position >= this->program.size()) {
        return std::nullopt;
    }

    char current_char = this->program[this->program_position];

    // Character string
    if (this->isQuote(current_char)) {
        return this->handleCharString();
    }

    // Comment
    if (this->isComment(current_char)) {
        this->handleComment();
        return std::nullopt;
    }

    // Reserved token from file or other token (identifier, constant, unrecognized symbol)
    return this->isReservedToken(current_char) ? this->handleReservedToken() : this->handleOtherToken();
}

void Scanner::classifyToken(const std::string& token) {
    std::optional<size_t> found_token;
    size_t key_code;

    // Check if the token is an identifier or a constant
    bool is_identifier = this->isIdentifier(token);
    if (is_identifier || this->isConstant(token)) {
        found_token = this->symbol_table.get(token);

        // Add the token to the symbol table if it's not already there
        if (!found_token) {
            this->symbol_table.add(token);
            found_token = this->symbol_table.getSymbolTableIndex() - 1;
        }

        // Determine the position based on whether it's an identifier or constant
        size_t position = is_identifier ? IDENTIFIER_POSITION : CONSTANT_POSITION;
        key_code = this->reserved_tokens.getSize() + position;
    }
    else {
        // Get the token code from the reserved_tokens hash table (if it's a reserved token)
        std::optional<size_t> reserved_token = this->reserved_tokens.get(token);

        // If the token is not in the hash table, and it's not an identifier or constant, it's an unrecognized symbol
        if (!reserved_token.has_value()) {
            throw std::runtime_error("Undefined token: " + token);
        }

        // Set the key code for reserved words
        key_code = *reserved_token;
        found_token = RESERVED_VALUE;
    }

    // Add the token to the PIF
    this->program_internal_form.push_back(std::make_pair(key_code, *found_token));
}

void Scanner::handleWhitespaceAndLineSeparator() {
    // Skip whitespaces and add line separators to PIF
    while (this->program_position < this->program.size()) {
        char current_char = this->program[this->program_position];

        if (current_char == LINE_SEPARATOR) {
            this->handleLineSeparator();
        }
        else if (!std::isspace(current_char)) {
            break;
        }

        this->program_position++;
    }
}

void Scanner::handleLineSeparator() {
    size_t key_code = this->reserved_tokens.getSize() + LINE_SEPARATOR_POSITION;
    this->program_internal_form.push_back(std::make_pair(key_code, RESERVED_VALUE));
    this->current_line++;
}

void Scanner::handleComment() {
    this->program_position++;             // Skip the comment start character

    while (this->program_position < this->program.size() && this->program[this->program_position] != LINE_SEPARATOR) {
        this->program_position++;
    }
}

std::string Scanner::handleCharString() {
    char quote = this->program[this->program_position++];        // Skip the opening quote
    std::string token{ quote };
 
    while (this->program_position < this->program.size() && this->program[this->program_position] != quote) {
        token.push_back(this->program[this->program_position++]);
    }

    if (this->program_position >= this->program.size() || this->program[this->program_position] != quote) {
        throw std::runtime_error("Unclosed char string starting at line " + std::to_string(this->current_line));
    }

    token.push_back(this->program[this->program_position++]);    // Skip the closing quote
    return token;
}

std::string Scanner::handleReservedToken() {
    std::string token;

    while (this->program_position < this->program.size()) {
        char current_char = this->program[this->program_position];

        // Perform a lookahead to see if the next character is also part of the reserved token
        std::string possible_token{ token + current_char };
        if (!this->isReservedToken(possible_token)) {
            break;
        }

        token.push_back(current_char);
        this->program_position++;
    }

    return token;
}

std::string Scanner::handleOtherToken() {
    std::string token;

    while (this->program_position < this->program.size()) {
        char current_char = this->program[this->program_position];
        std::string ch_str{ current_char };

        if (isspace(current_char)) {
            // If it's a space, end the current token
            if (!token.empty()) {
                break;
            }

            this->program_position++;
            continue;
        }

        // If it's a reserved token and the current token buffer is empty, it should be handled by handleReservedToken()
        if (this->isReservedToken(ch_str)) {
            break;
        }

        if (!isalnum(current_char) && current_char != '@') {
            // If there's something in the token buffer, we've reached the end of an identifier or number
            if (!token.empty()) {
                break;
            }

            // If it's not alphanumeric or '@' (for identifiers), and the token buffer is empty, it's an unrecognized symbol
            this->program_position++;
            token.push_back(current_char);
            return token;
        }

        // Add the character to the token buffer
        this->program_position++;
        token.push_back(current_char);
    }

    return token;
}

void Scanner::print() {
    std::cout << "Program Internal form:\n";
    for (const auto& [token, position] : this->program_internal_form) {
        std::cout << "Token: " << token << ", Position: " << position << "\n";
    }

    std::cout << "\nSymbol Table:\n";
    std::cout << this->symbol_table;
}

void Scanner::outputPIF(const std::string& output_file_path) {
    std::ofstream file(output_file_path);
    if (!file.is_open()) {
        throw std::runtime_error("Unable to open PIF output file: " + output_file_path);
    }

    file << "Program Internal Form (PIF):\n";
    file << "Token | Symbol Table Position\n";
    for (const auto& [token, position] : this->program_internal_form) {
        file << token << " | " << position << "\n";
    }
}

void Scanner::outputST(const std::string& output_file_path) {
    std::ofstream file(output_file_path);
    if (!file.is_open()) {
        throw std::runtime_error("Unable to open ST output file: " + output_file_path);
    }

    file << "Symbol Table:\n";
    file << this->symbol_table;
}
