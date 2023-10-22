#ifndef _SYMBOLTABLE_H_
#define _SYMBOLTABLE_H_

#include "HashTable.h"

#include <iostream>

template<typename K>
class SymbolTable {
private:
    HashTable<K, size_t> table;         // Unique table for identifiers and constants
    size_t table_index;                 // Auto-increment index for table entries

public:
    // Default constructor: creates an empty symbol table
    SymbolTable() : table_index{ 0 } {}

    // Adds a new entry to the symbol table
    void add(const K& key);

    // Removes an entry from the symbol table
    void remove(const K& key);

    // Returns the index of an entry in the symbol table
    std::optional<size_t> get(const K& key) const;

    size_t getSize() const;

    HashTable<K, size_t> getTable() const {
        return this->table;
    }

    size_t getSymbolTableIndex() const {
        return this->table_index;
    }

    // Removes all entries from the symbol table
    void clear();

    bool isEmpty() const {
        return this->table.isEmpty();
    }

    friend std::ostream& operator<<(std::ostream& os, const SymbolTable<K>& table) {
        os << "Symbol table:\n" << table.getTable() << "Size: " << table.getSize() << "\n";

        return os;
    }
};


template<typename K>
void SymbolTable<K>::add(const K& key) {
    size_t old_size = this->getSize();
    this->table.add(key, this->table_index);

    // Increment index only if add was successful
    if (this->getSize() > old_size) {
        this->table_index++;
    }
}


template<typename K>
void SymbolTable<K>::remove(const K& key)
{
    this->table.remove(key);
}


template<typename K>
std::optional<size_t> SymbolTable<K>::get(const K& key) const {
    auto optValue = this->table.get(key);
    return optValue ? *optValue : std::optional<size_t>{};
}


template<typename K>
size_t SymbolTable<K>::getSize() const
{
    return this->table.getSize();
}


template<typename K>
void SymbolTable<K>::clear()
{
    this->table.clear();
    this->table_index = 0;
}

#endif // _SYMBOLTABLE_H_
