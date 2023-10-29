#include "Scanner.h"

Scanner::Scanner(const std::string& token_file_path) : program_position{ 0 }, current_line{ 0 } {
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
        this->reserved_tokens.add(line, ++index);
    }

    if (!token_file.eof()) {
        throw std::runtime_error("Error occurred while reading the token file.");
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
        throw std::runtime_error("Error occurred while reading the program file.");
    }

    std::cout << "Finished reading program from '" << program_file_path << "'\n";
}

void Scanner::scan(const std::string& program_file_path) {
    this->readProgramFile(program_file_path);
    this->program_position = 0;
    this->current_line = 1;

    try {
        this->parseProgram();
    }
    catch (const std::runtime_error& e)
    {
        throw std::runtime_error("Lexical error on line " + std::to_string(this->current_line) + ": " + e.what() + "\n");
    }

    std::cout << "Finished scanning file '" << program_file_path << "'\n";
}

void Scanner::parseProgram() {
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

    // Comment
    if (current_char == '~') {
        this->handleComment();
        return std::nullopt;
    }

    // Character string
    if (current_char == '\'' || current_char == '\"') {
        return this->handleCharString();
    }

    // Reserved token from file
    std::string ch_str{ current_char };
    if (this->reserved_tokens.contains(ch_str)) {
        return this->handleReservedToken();
    }
   
    // Other token (identifier, constant, unrecognized symbol)
    return this->handleOtherToken();
}

void Scanner::classifyToken(const std::string& token) {
    // Get the token code from the reserved_tokens hash table (from the token file)
    std::optional<size_t> key_code = this->reserved_tokens.get(token);

    if (key_code.has_value()) {
        // Reserved word or line separator
        this->program_internal_form.push_back(std::make_pair(*key_code, RESERVED_VALUE));
    }
    else if (this->isIdentifier(token) || this->isConstant(token)) {
        // Identifier or constant
        std::optional<size_t> found_token = this->symbol_table.get(token);

        // Add the token to the symbol table if it's not already there
        if (!found_token.has_value()) {
            this->symbol_table.add(token);
            found_token = this->symbol_table.get(token);
        }

        // Add the token to the PIF
        if (found_token.has_value()) {
            size_t position = this->isIdentifier(token) ? IDENTIFIER_POSITION : CONSTANT_POSITION;
            size_t key_code = this->reserved_tokens.getSize() + position;
            this->program_internal_form.push_back(std::make_pair(key_code, *found_token));
        }
    }
    else {
        throw std::runtime_error("Undefined token: " + token);
    }
}

void Scanner::handleWhitespaceAndLineSeparator() {
    // Skip whitespaces and add line separators to PIF
    while (this->program_position < this->program.size()) {
        char current_char = this->program[this->program_position];

        if (current_char == '\n') {
            size_t key_code = this->reserved_tokens.getSize() + LINE_SEPARATOR_POSITION;
            this->program_internal_form.push_back(std::make_pair(key_code, RESERVED_VALUE));
            this->current_line++;
        }
        else if (!std::isspace(current_char)) {
            return;
        }

        this->program_position++;
    }
}

void Scanner::handleComment() {
    // Skip the comment
    while (this->program_position < this->program.size() && this->program[this->program_position] != '\n') {
        this->program_position++;
    }
}

std::string Scanner::handleCharString() {
    char quote = this->program[this->program_position];
    std::string token{ quote };

    size_t start_position = this->program_position;
    this->program_position++;            // Skip the opening quote
 
    while (this->program_position < this->program.size() && this->program[this->program_position] != quote) {
        token.push_back(this->program[this->program_position]);
        this->program_position++;
    }

    if (this->program[this->program_position] != quote) {
        throw std::runtime_error("Unclosed char string starting at line " + std::to_string(this->current_line) + " and position " + std::to_string(start_position));
	}

    if (this->program_position >= this->program.size()) {
        throw std::runtime_error("End of file reached while parsing a string constant.");
    }

    token.push_back(quote);             // Add the closing quote to the token
    this->program_position++;           // Skip the closing quote
    return token;
}

std::string Scanner::handleReservedToken() {
    std::string token;

    while (this->program_position < this->program.size()) {
        char current_char = this->program[this->program_position];

        // Perform a lookahead to see if the next character is also part of the reserved token
        std::string possible_token{ token + current_char };
        if (!this->reserved_tokens.contains(possible_token)) {
            break;
        }

        this->program_position++;
        token.push_back(current_char);
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
        if (this->reserved_tokens.contains(ch_str)) {
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
        throw std::runtime_error("Unable to open PIF output file!");
    }

    file << "Program Internal Form:\n";
    file << "Token : Symbol Table Position\n";
    for (const auto& [token, position] : this->program_internal_form) {
        file << token << " : " << position << "\n";
    }

    file.close();
}

void Scanner::outputST(const std::string& output_file_path) {
    std::ofstream file(output_file_path);
    if (!file.is_open()) {
        throw std::runtime_error("Unable to open ST output file!");
    }

    file << "Symbol Table:\n";
    file << this->symbol_table;
    file.close();
}
