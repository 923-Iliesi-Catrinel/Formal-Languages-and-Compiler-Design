#include "Scanner.h"

#include <iostream>

const std::string TOKEN_FILE_PATH = "../../../Lab 1b/token.in";
const std::string PROGRAM1_FILE_PATH = "../../../Lab 1a/p1.cat";
const std::string PROGRAM1_ERR_FILE_PATH = "../../../Lab 1a/p1err.cat";
const std::string PROGRAM2_FILE_PATH = "../../../Lab 1a/p2.cat";
const std::string PROGRAM3_FILE_PATH = "../../../Lab 1a/p3.cat";
const std::string OUTPUT_DIR = "output/";

void scanProgram(const std::string& program_file_path, const std::string& program_name) {
    try {
        Scanner scanner(TOKEN_FILE_PATH);
        scanner.scan(program_file_path);
        std::cout << program_name + " is lexically correct.\n\n";

        scanner.outputPIF(OUTPUT_DIR + program_name + "PIF.out");
        scanner.outputST(OUTPUT_DIR + program_name + "ST.out");
        //scanner.print();
    }
    catch (const std::runtime_error& e) {
       std::cout << program_name + ": " + e.what() + "\n";
    }
}

int main() {
    scanProgram(PROGRAM1_FILE_PATH, "p1");
    scanProgram(PROGRAM1_ERR_FILE_PATH, "p1err");
    scanProgram(PROGRAM2_FILE_PATH, "p2");
    scanProgram(PROGRAM3_FILE_PATH, "p3");

    return 0;
}
