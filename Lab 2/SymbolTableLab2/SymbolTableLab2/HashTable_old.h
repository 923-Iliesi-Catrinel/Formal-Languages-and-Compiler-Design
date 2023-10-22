#include <iostream>
#include <vector>
#include <string>
#include <functional>

#define DEFAULT_CAPACITY 16

template <typename T>
class HashTable {
private:
    struct HashNode {
        T key;
        bool filled = false;
        bool deleted = false;
    };

    HashNode* table;
    int capacity = DEFAULT_CAPACITY;
    int size = 0;

    int hash(const T& key) const {
        return std::hash<T>{}(key) % this->capacity;
    }

    // Performs linear probing to resolve collisions; calculates the next available position after a collision
    int probe(int currentPos, int step) const {
        return (currentPos + step) % this->capacity;
    }

    // Doubles the capacity of the hash table and rehashes the existing elements when the load factor exceeds 0.75
    void resize() {
        int oldCapacity = this->capacity;
        this->capacity *= 2;

        HashNode* oldTable = this->table;
        this->table = new HashNode[this->capacity];

        for (int i = 0; i < oldCapacity; i++) {
            if (oldTable[i].filled && !oldTable[i].deleted) {
                add(oldTable[i].key);
            }
        }

        delete[] oldTable;
    }

public:
    HashTable() {
        this->table = new HashNode[this->capacity];
    }

    ~HashTable() {
        delete[] this->table;
    }

    // BC time complexity: O(1) (no collisions)
    // AC time complexity : O(1)
    // WS time complexity : O(n) (n is the number of keys and many collisions occur, which could require traversing the entire table)
    void add(const T& key) {
        if ((static_cast<float>(this->size) / this->capacity) >= 0.75) {
            resize();
        }

        int position = hash(key);
        int step = 1;

        while (this->table[position].filled && !this->table[position].deleted) {
            if (this->table[position].key == key) {
                return;
            }

            position = probe(position, step++);
        }

        this->table[position].key = key;
        this->table[position].filled = true;
        this->table[position].deleted = false;
        this->size++;
    }

    // BC time complexity: O(1) (no collisions occur, key is found in initial hash position)
    // AC time complexity : O(1)
    // WC time complexity : O(n) (requires traversing the entire table)
    int contains(const T& key) const {
        int position = hash(key);
        int step = 1;

        while (this->table[position].filled || this->table[position].deleted) {
            if (this->table[position].key == key && !this->table[position].deleted) {
                return position;
            }

            position = probe(position, step++);
        }

        return -1;
    }

    // BC time complexity: O(1) (no collisions occur, key is found in initial hash position)
    // AC time complexity : O(1)
    // WC time complexity : O(n) (requires traversing the entire table)
    void remove(const T& key) {
        int position = hash(key);
        int step = 1;

        while (this->table[position].filled || this->table[position].deleted) {
            if (this->table[position].key == key && !this->table[position].deleted) {
                this->table[position].deleted = true;
                this->size--;
                return;
            }
            position = probe(position, step++);
        }
    }

    int getSize() const {
        return this->size;
    }

    std::string toString() const {
        std::string result;

        for (int i = 0; i < capacity; i++) {
            if (this->table[i].filled) {
                if constexpr (std::is_same_v<T, std::string>) {
                    result += (this->table[i].key.empty() ? "EMPTY" : this->table[i].key) + " ";
                }
                else {
                    result += std::to_string(this->table[i].key) + " ";
                }
            }
            else {
                result += "EMPTY ";
            }
        }
        return result;
    }
};
