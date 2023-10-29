#ifndef _HASHTABLE_H_
#define _HASHTABLE_H_

#include <vector>
#include <string>
#include <functional>
#include <optional>
#include <sstream>

const size_t DEFAULT_CAPACITY = 16;
const double LOAD_FACTOR = 0.75;
const size_t RESIZE_FACTOR = 2;

// Status of a hash table entry
enum EntryStatus { 
    EMPTY, 
    FILLED, 
    DELETED 
};

// Hash table entry
template<typename K, typename V>
struct HashNode {
    K key;
    V value;
    EntryStatus status = EntryStatus::EMPTY;
};

template<typename K, typename V>
class HashTable {
private:
    std::vector<HashNode<K, V>> table;
    size_t capacity;
    size_t size;                      // Number of filled entries

    // Primary hash function
    size_t hash1(const K& key) const {
        return std::hash<K>{}(key) % this->capacity;
    }

    // Secondary hash function (used for double hashing)
    size_t hash2(const K& key) const {
        return 1 + (std::hash<K>{}(key) % (this->capacity - 1));
    }

    // Performs probing for double hashing to solve collisions; calculates the next available position after a collision
    size_t probe(size_t current_position, size_t step) const {
        return (current_position + step) % this->capacity;
    }

    // Resizes the hash table by increasing its capacity by RESIZE_FACTOR
    // Best Case time complexity: O(n)
    // Average Case time complexity: O(n)
    // Worst Case time complexity: O(n)
    void resize();

public:
    // Default constructor: creates a hash table with DEFAULT_CAPACITY
    HashTable() : table{ DEFAULT_CAPACITY }, capacity{ DEFAULT_CAPACITY }, size{ 0 } {}

    // Adds a new key-value pair to the hash table
    // Best Case time complexity: O(1) (no collisions)
    // Average Case time complexity: O(1)
    // Worst Case time complexity: O(n) (n is the number of keys and many collisions occur, which could require traversing the entire table)
    void add(const K& key, const V& value);

    // Removes a key-value pair from the hash table
    // Best Case time complexity: O(1) (no collisions occur, key is found in initial hash position)
    // Average Case time complexity: O(1)
    // Worst Case time complexity: O(n) (requires traversing the entire table)
    void remove(const K& key);

    // Returns the value associated with a key, if it exists, or std::nullopt otherwise
    // Best Case time complexity: O(1) (no collisions occur, key is found in initial hash position)
    // Average Case time complexity: O(1)
    // Worst Case time complexity: O(n) (requires traversing the entire table)
    std::optional<V> get(const K& key) const;

    // Returns true if the hash table contains the specified key, or false otherwise
    // Best Case time complexity: O(1) (no collisions occur, key is found in initial hash position)
    // Average Case time complexity: O(1)
    // Worst Case time complexity: O(n) (requires traversing the entire table)
    bool contains(const K& key) const;

    // Removes all key-value pairs from the hash table
    void clear();

    size_t getSize() const {
        return this->size;
    }

    size_t getCapacity() const {
        return this->capacity;
    }

    bool isEmpty() const {
        return this->size == 0;
    }

    // Returns the hash table in a printable string format
    // Best Case time complexity: O(n)
    // Average Case time complexity: O(n)
    // WS time complexity: O(n)
    friend std::ostream& operator<<(std::ostream& os, const HashTable<K, V>& hash_table) {
        for (size_t i = 0; i < hash_table.capacity; i++) {
            if (hash_table.table[i].status == EntryStatus::FILLED) {
                os << "Position: " << i << " -> {Key: " << hash_table.table[i].key << ", Value: " << hash_table.table[i].value << "}\n";
            }
        }

        os << "Size: " << hash_table.size << "\n";

        return os;
    }
};

template<typename K, typename V>
void HashTable<K, V>::add(const K& key, const V& value) {
    // Resize the hash table if the load factor is exceeded
    if ((static_cast<double>(this->size) / this->capacity) >= LOAD_FACTOR) {
        this->resize();
    }

    size_t position = this->hash1(key);
    size_t step = this->hash2(key);
    size_t collision_counter = 0;       // Used to avoid infinite loop when the table is full

    while (collision_counter < this->capacity) {
        if (this->table[position].key == key && this->table[position].status == EntryStatus::FILLED) {
            return;  // Key already exists
        }

        if (this->table[position].status != EntryStatus::FILLED) {
            this->table[position] = { key, value, EntryStatus::FILLED };
            this->size++;
            return;
        }

        // Find next available position using double hashing
        position = this->probe(position, step);
        collision_counter++;
    }
}

template<typename K, typename V>
void HashTable<K, V>::remove(const K& key) {
    size_t position = this->hash1(key);
    size_t step = this->hash2(key);
    size_t collision_counter = 0;       // Used to avoid infinite loop when the table is full

    while (collision_counter < this->capacity) {
        if (this->table[position].key == key && this->table[position].status == EntryStatus::FILLED) {
            this->table[position].status = EntryStatus::DELETED;
            this->size--;
            return;
        }

        // If the slot is empty, then the key was not found
        if (this->table[position].status == EntryStatus::EMPTY) {
            return;
        }

        // Find next available position using double hashing
        position = this->probe(position, step);
        collision_counter++;
    }
}

template<typename K, typename V>
std::optional<V> HashTable<K, V>::get(const K& key) const {
    size_t position = this->hash1(key);
    size_t step = this->hash2(key);
    size_t collision_counter = 0;       // Used to avoid infinite loop when the table is full

    while (collision_counter < this->capacity) {
        if (this->table[position].key == key && this->table[position].status == EntryStatus::FILLED) {
            return this->table[position].value;
        }

        // If the slot is empty, then the key was not found
        if (this->table[position].status == EntryStatus::EMPTY) {
            break;
        }

        // Find next available position using double hashing
        position = this->probe(position, step);
        collision_counter++;
    }

    return {};
}

template<typename K, typename V>
bool HashTable<K, V>::contains(const K& key) const {
    size_t position = this->hash1(key);
	size_t step = this->hash2(key);
	size_t collision_counter = 0;       // Used to avoid infinite loop when the table is full

    while (collision_counter < this->capacity) {
        if (this->table[position].key == key && this->table[position].status == EntryStatus::FILLED) {
			return true;
		}
		// If the slot is empty, then the key was not found
        if (this->table[position].status == EntryStatus::EMPTY) {
			break;
		}

		// Find next available position using double hashing
		position = this->probe(position, step);
		collision_counter++;
	}

	return false;   
}

template<typename K, typename V>
void HashTable<K, V>::resize() {
    size_t old_capacity = this->capacity;
    this->capacity *= RESIZE_FACTOR;

    std::vector<HashNode<K, V>> new_table(this->capacity);
    std::swap(this->table, new_table);
    this->size = 0;

    for (size_t i = 0; i < old_capacity; i++) {
        if (new_table[i].status == EntryStatus::FILLED) {
            this->add(new_table[i].key, new_table[i].value);
        }
    }
}

template<typename K, typename V>
void HashTable<K, V>::clear() {
    this->table = std::vector<HashNode<K, V>>(DEFAULT_CAPACITY);
    this->capacity = DEFAULT_CAPACITY;
    this->size = 0;
}

#endif // _HASH_TABLE_H
