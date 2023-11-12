#include "FiniteAutomata.h"

const std::string FA_IDENTIFIER_FILE_PATH = "input/FAidentifier.in";
const std::string FA_INT_CONSTANT_FILE_PATH = "input/FAint_constant.in";
const std::string FA_CHAR_CONSTANT_FILE_PATH = "input/FAchar_constant.in";
const std::string FA_STRING_CONSTANT_FILE_PATH = "input/FAstring_constant.in";

enum MenuOption {
    Exit,
    DisplayStates,
    DisplayAlphabet,
    DisplayTransitions,
    DisplayInitialState,
    DisplayFinalStates,
    CheckSequence
};

void displayMenu() {
    std::cout << "\nFinite Automata\n";
    std::cout << "Menu:\n";
    std::cout << "1. Display the set of states.\n";
    std::cout << "2. Display the alphabet.\n";
    std::cout << "3. Display all transitions.\n";
    std::cout << "4. Display the initial state.\n";
    std::cout << "5. Display the set of final states.\n";
    std::cout << "6. Check if a sequence is accepted by the FA.\n";
    std::cout << "0. Exit.\n";
}

void clearCinErrors() {
    std::cin.clear();                                                   // Clears any error flags
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discards the input buffer
}

bool getUserConfirmation() {
    std::cout << "Are you sure you want to exit? (y/n): ";
    char response;
    std::cin >> response;
    return (response == 'y' || response == 'Y');
}

std::string getFilePathFromUser() {
    std::string filePath;
    std::cout << "Enter the file path for the Finite Automata: ";
    std::cin >> filePath;
    return filePath;
}

void displayStates(const FiniteAutomata<std::string, char>& fa) {
    std::cout << fa.statesToString() << "\n";
}

void displayAlphabet(const FiniteAutomata<std::string, char>& fa) {
    std::cout << fa.alphabetToString() << "\n";
}

void displayTransitions(const FiniteAutomata<std::string, char>& fa) {
    std::cout << fa.transitionsToString() << "\n";
}

void displayInitialState(const FiniteAutomata<std::string, char>& fa) {
    std::cout << fa.initialStateToString() << "\n";
}

void displayFinalStates(const FiniteAutomata<std::string, char>& fa) {
    std::cout << fa.finalStatesToString() << "\n";
}

void checkSequence(const FiniteAutomata<std::string, char>& fa) {
    std::string sequence;
    std::cout << "Enter a sequence to verify: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, sequence);

    if (fa.accepts(sequence)) {
        std::cout << "Sequence is accepted by the FA.\n";
    }
    else {
        std::cout << "Sequence is not accepted by the FA.\n";
    }
}

int main() {
    try {
        // std::string filePath = getFilePathFromUser();
        //FiniteAutomata<std::string, char> finite_automata(filePath);
        FiniteAutomata<std::string, char> finite_automata(FA_STRING_CONSTANT_FILE_PATH);
        //FiniteAutomata<std::string, char> finite_automata(FA_CONSTANT_FILE_PATH);
        MenuOption user_option = Exit;

        do {
            displayMenu();
            std::cout << "Select an option: ";
            size_t input;
            std::cin >> input;
            if (std::cin.fail()) {
                clearCinErrors();
                std::cout << "Invalid input, please enter a number.\n";
                continue;
            }

            user_option = static_cast<MenuOption>(input);

            switch (user_option) {
            case DisplayStates:
                displayStates(finite_automata);
                break;
            case DisplayAlphabet:
                displayAlphabet(finite_automata);
                break;
            case DisplayTransitions:
                displayTransitions(finite_automata);
                break;
            case DisplayInitialState:
                displayInitialState(finite_automata);
                break;
            case DisplayFinalStates:
                displayFinalStates(finite_automata);
                break;
            case CheckSequence:
                checkSequence(finite_automata);
                break;
            case Exit:
                if (!getUserConfirmation()) {
                    user_option = DisplayStates;
                }
                else {
                    std::cout << "Exiting...\n";
                }
                break;
            default:
                std::cout << "Invalid option, please try again.\n";
            }
        } while (user_option != Exit);

    }
    catch (const std::exception& e) {
        std::cerr << "ERROR: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
