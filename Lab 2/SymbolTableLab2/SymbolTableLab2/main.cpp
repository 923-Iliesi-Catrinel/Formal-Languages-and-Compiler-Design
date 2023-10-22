#include "SymbolTable.h"

#include <iostream>
#include <cassert>

int main()
{
    std::cout << "Starting tests...\n\n";

    SymbolTable<std::string> symbol_table;

    assert(symbol_table.isEmpty() == true);
    assert(symbol_table.getSize() == 0);
    assert(symbol_table.getSymbolTableIndex() == 0);

    // Add a new identifier to the symbol table
    symbol_table.add("x");

    // Add a new constant to the symbol table
    symbol_table.add("\"x\"");

    symbol_table.add("@y");

    assert(symbol_table.isEmpty() == false);
    assert(symbol_table.getSize() == 3);
    assert(symbol_table.getSymbolTableIndex() == 3);
    assert(symbol_table.get("x") == 0);
    assert(symbol_table.get("\"x\"") == 1);
    assert(symbol_table.get("@y") == 2);

    // Try to retrieve non-existent element
    assert(symbol_table.get("ab") == std::nullopt);

    std::cout << symbol_table;
    std::cout << "Get test passed...\n\n";

    // Try to add duplicate element
    symbol_table.add("x");
    assert(symbol_table.getSize() == 3);
    assert(symbol_table.getSymbolTableIndex() == 3);

    std::cout << "Add test passed...\n\n";

    symbol_table.remove("\"x\"");
    assert(symbol_table.getSize() == 2);
    assert(symbol_table.getSymbolTableIndex() == 3);
    assert(symbol_table.get("\"x\"") == std::nullopt);

    // Try to remove non-existent element
    symbol_table.remove("aaa");

    std::cout << symbol_table;
    std::cout << "Remove test passed...\n\n";

    symbol_table.add("1");
    symbol_table.add("4.5");
    symbol_table.add("\"a4.5\"");
    symbol_table.add("\"hello!\"");

    assert(symbol_table.getSize() == 6);
    assert(symbol_table.getSymbolTableIndex() == 7);
    assert(symbol_table.get("1") == 3);
    assert(symbol_table.get("4.5") == 4);
    assert(symbol_table.get("\"a4.5\"") == 5);
    assert(symbol_table.get("\"hello!\"") == 6);
    assert(symbol_table.get("\"hello\"") == std::nullopt);

    std::cout << symbol_table;

    symbol_table.clear();
    assert(symbol_table.isEmpty() == true);
    assert(symbol_table.getSize() == 0);
    assert(symbol_table.getSymbolTableIndex() == 0);

    std::cout << "Clear test passed...\n\n";

    std::cout << "All tests passed!\n\n";

    return 0;
}
