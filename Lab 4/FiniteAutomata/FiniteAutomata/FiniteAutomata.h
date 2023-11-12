#ifndef _FINITE_AUTOMATA_H_
#define _FINITE_AUTOMATA_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <tuple>
#include <set>
#include <string>


template<typename StateType, typename SymbolType>
class FiniteAutomata {
private:
    std::set<StateType> states;
    std::set<SymbolType> alphabet;
    StateType initial_state;
    std::set<StateType> final_states;
    std::map<std::pair<StateType, SymbolType>, StateType> transitions;

    static const char FA_SEPARATOR = ' ';

public:
    // Constructs a Finite Automata object by loading its configuration from a given file.
    FiniteAutomata(const std::string& filename);
    
    // Checks if the given sequence is accepted by the automata
    bool accepts(const std::string& sequence) const;

    // Generates a string representation of the states of the automata
    std::string statesToString() const;

    // Generates a string representation of the alphabet of the automata
    std::string alphabetToString() const;

    // Generates a string representation of the transitions of the automata
    std::string transitionsToString() const;

    // Generates a string representation of the initial state of the automata
    std::string initialStateToString() const;

    // Generates a string representation of the final states of the automata
    std::string finalStatesToString() const;

private:
    // Loads the automata's configuration from a given file
    void loadFromFile(const std::string& file_path);

    // Utility function for splitting a string into a vector of strings based on a delimiter
    std::vector<std::string> split(const std::string& str, char delimiter) const;
};

template<typename StateType, typename SymbolType>
FiniteAutomata<StateType, SymbolType>::FiniteAutomata(const std::string& filename)
{
    this->loadFromFile(filename);
}

template<typename StateType, typename SymbolType>
bool FiniteAutomata<StateType, SymbolType>::accepts(const std::string& sequence) const {
    // No transitions occur, and the automaton stays in its initial state
    if (sequence.empty()) {
        return this->final_states.count(this->initial_state) > 0;
    }

    StateType current_state = this->initial_state;
    for (auto symbol : sequence) {
        SymbolType transition_symbol = (symbol == ' ') ? '~' : symbol;

        auto transition_key = std::make_pair(current_state, transition_symbol);
        auto it = this->transitions.find(transition_key);
        if (it == this->transitions.end()) {
            return false;  // Transition does not exist
        }

        // Current state is updated to the target state of the transition
        current_state = it->second;
    }

    // Check if the current state is one of the final states
    return this->final_states.count(current_state) > 0;
}

template<typename StateType, typename SymbolType>
std::string FiniteAutomata<StateType, SymbolType>::statesToString() const {
    std::ostringstream oss;
    oss << "Set of states: ";
    for (const auto& state : this->states) {
        oss << state << " ";
    }

    return oss.str();
}

template<typename StateType, typename SymbolType>
std::string FiniteAutomata<StateType, SymbolType>::alphabetToString() const {
    std::ostringstream oss;
    oss << "Alphabet: ";
    for (char symbol : this->alphabet) {
        oss << symbol << " ";
    }

    return oss.str();
}

template<typename StateType, typename SymbolType>
std::string FiniteAutomata<StateType, SymbolType>::transitionsToString() const {
    std::ostringstream oss;
    oss << "Transitions:\n";
    for (const auto& transition : this->transitions) {
        oss << transition.first.first << " " << transition.first.second << " " << transition.second << "\n";
    }

    return oss.str();
}

template<typename StateType, typename SymbolType>
std::string FiniteAutomata<StateType, SymbolType>::initialStateToString() const {
    std::ostringstream oss;
    oss << "Initial state: " << this->initial_state;
    return oss.str();
}

template<typename StateType, typename SymbolType>
std::string FiniteAutomata<StateType, SymbolType>::finalStatesToString() const {
    std::ostringstream oss;
    oss << "Final states: ";
    for (const auto& finalState : this->final_states) {
        oss << finalState << " ";
    }

    return oss.str();
}

// Converts a string to a template type T
template<typename T>
inline T convertFromString(const std::string& str);

template<>
inline std::string convertFromString<std::string>(const std::string& str) {
    return str;
}

template<>
inline char convertFromString<char>(const std::string& str) {
    return str.empty() ? '\0' : str[0];
}

template<typename StateType, typename SymbolType>
void FiniteAutomata<StateType, SymbolType>::loadFromFile(const std::string& file_path) {
    std::ifstream file(file_path);
    if (!file.is_open()) {
        throw std::runtime_error("Unable to open finite automata file at " + file_path);
    }

    try {
        // Load states
        std::string line;
        if (!std::getline(file, line)) {
            throw std::runtime_error("Unable to read states from file at " + file_path);
        }

        auto state_tokens = this->split(line, FA_SEPARATOR);
        for (const auto& state_str : state_tokens) {
            this->states.insert(convertFromString<StateType>(state_str));
        }

        // Load alphabet
        if (!std::getline(file, line)) {
            throw std::runtime_error("Unable to read alphabet from file at " + file_path);
        }

        auto alphabet_tokens = this->split(line, FA_SEPARATOR);
        for (const auto& symbol_str : alphabet_tokens) {
            this->alphabet.insert(convertFromString<SymbolType>(symbol_str));
        }

        // Load initial state
        if (!std::getline(file, line)) {
            throw std::runtime_error("Unable to read initial state from file at " + file_path);
        }

        this->initial_state = convertFromString<StateType>(line);
        if (this->states.find(this->initial_state) == this->states.end()) {
            throw std::runtime_error("Initial state not in the set of states in file at " + file_path);
        }

        // Load final states
        if (!std::getline(file, line)) {
            throw std::runtime_error("Unable to read final states from file at " + file_path);
        }

        auto final_state_tokens = this->split(line, FA_SEPARATOR);
        for (const auto& final_state_str : final_state_tokens) {
            StateType final_state = convertFromString<StateType>(final_state_str);
            if (this->states.find(final_state) == this->states.end()) {
                throw std::runtime_error("Final state not in the set of states in file at " + file_path);
            }

            this->final_states.insert(final_state);
        }

        // Load transitions
        while (std::getline(file, line)) {
            auto transition_tokens = this->split(line, FA_SEPARATOR);
            if (transition_tokens.size() != 3) {
                throw std::runtime_error("Invalid transition format in file at " + file_path);
            }

            StateType from_state = convertFromString<StateType>(transition_tokens[0]);
            SymbolType symbol = convertFromString<SymbolType>(transition_tokens[1]);
            StateType to_state = convertFromString<StateType>(transition_tokens[2]);

            if (this->states.find(from_state) == this->states.end() || this->states.find(to_state) == this->states.end()) {
                throw std::runtime_error("Transition states not in the set of states in file at " + file_path);
            }
            if (this->alphabet.find(symbol) == this->alphabet.end()) {
                throw std::runtime_error("Transition symbol " + std::to_string(symbol) + " not in the alphabet in file at " + file_path);
            }

            this->transitions[{from_state, symbol}] = to_state;
        }
    }
    catch (const std::runtime_error&) {
        throw;
    }
}

template<typename StateType, typename SymbolType>
std::vector<std::string> FiniteAutomata<StateType, SymbolType>::split(const std::string& str, char delimiter) const {
    std::vector<std::string> tokens;
    size_t start = 0;
    size_t end = str.find(delimiter);

    while (end != std::string::npos) {
        tokens.push_back(str.substr(start, end - start));
        start = end + 1;
        end = str.find(delimiter, start);
    }

    tokens.push_back(str.substr(start));
    return tokens;
}

#endif // _FINITE_AUTOMATA_H_
