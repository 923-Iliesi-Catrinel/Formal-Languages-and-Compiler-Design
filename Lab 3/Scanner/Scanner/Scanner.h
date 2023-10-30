#ifndef _SCANNER_H_
#define _SCANNER_H_

#include "../../../Lab 2/SymbolTableLab2/SymbolTableLab2/SymbolTable.h"

#include <regex>
#include <fstream>
#include <iostream>
#include <algorithm>

const std::string LINE_SEPARATOR = "\\n";
const size_t IDENTIFIER_POSITION = 1;
const size_t CONSTANT_POSITION = 2;
const size_t LINE_SEPARATOR_POSITION = 3;
const size_t RESERVED_VALUE = 0;

const std::regex IDENTIFIER_PATTERN{ R"(^@[A-Za-z][A-Za-z0-9]*$)" };
const std::regex NUMBER_PATTERN{ R"(^((\+|-)?[1-9][0-9]*)|0$)" };
const std::regex STRING_PATTERN{ R"(^"[^"]*"$|'^[^']*'$)" };

class Scanner {
private:
    std::vector<std::pair<size_t, size_t>> program_internal_form;
    SymbolTable<std::string> symbol_table;
    HashTable<std::string, size_t> reserved_tokens;

    std::vector<char> program;
    size_t program_position;
    size_t current_line;

public:
    // Constructs a Scanner object and initializes reserved tokens from the given file
    Scanner(const std::string& token_file_path);

    // Scans the program file, detects, classifies and codifies the tokens
    void scan(const std::string& program_file_path);

    // Prints the Program Internal Form and Symbol Table to the console
    void print();

    // Outputs the Program Internal Form to the given file
    void outputPIF(const std::string& output_file_path);

    // Outputs the Symbol Table to the given file
    void outputST(const std::string& output_file_path);

private:
    // Checks if the given token matches the pattern for an identifier
    bool isIdentifier(const std::string& token) {
        return std::regex_match(token, IDENTIFIER_PATTERN);
    }

    // Checks if the given token matches the pattern for a constant
    bool isConstant(const std::string& token) {
        return std::regex_match(token, NUMBER_PATTERN) || std::regex_match(token, STRING_PATTERN);
    }

    // Checks if the given token is the beginning of a comment
    bool isComment(const char& token) {
        return token == '~';
    }

    // Checks if the given token is a quote (beginning of a character string)
    bool isQuote(const char& token) {
        return token == '\'' || token == '\"';
    }

    // Reads and stores reserved tokens from the given file into the reserved_tokens hash table
    void readTokenFile(const std::string& token_file_path);

    // Reads the program file into memory in program vector for scanning
    void readProgramFile(const std::string& program_file_path);

    // Parses the program file, extracting and classifying tokens
    void parse();

    // Classifies and codifies a token and stores it in the Program Internal Form and Symbol Table if it's not already there
    void classifyToken(const std::string& token);

    // Retrieves the next token from the program file
    std::optional<std::string> nextToken();

    // Skips whitespace characters and handles line separators
    void handleWhitespaceAndLineSeparator();

    // Skips over comments in the program file
    void handleComment();

    // Handles character strings, along with their opening and closing quotes
    std::string handleCharString();

    // Handles reserved tokens
    std::string handleReservedToken();

    // Handles other types of tokens not covered by the other functions
    std::string handleOtherToken();
};

#endif // _SCANNER_H_
