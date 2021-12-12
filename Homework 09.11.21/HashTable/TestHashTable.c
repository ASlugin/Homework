#include "TestHashTable.h"
#include "HashTable.h"
#include <math.h>

bool isTestHashTablePassing(void)
{
    HashTable* table = createHashTable();
    if (table == NULL)
    {
        return false;
    }
    if (!readDataFromFile(table, "InputTest.txt"))
    {
        deleteHashTable(&table);
        return false;
    }
    
    if (getNumberOfOccurrences(table, "first") != 2 || getNumberOfOccurrences(table, "second") != 3
        || getNumberOfOccurrences(table, "four") != 1 || getNumberOfOccurrences(table, "seven") != 0)
    {
        deleteHashTable(&table);
        return false;
    }

    bool result = 0.93 - getLoadFactor(table) < 0.001 && getMaximumLength(table) == 3 && 0.73 - getAvarageLength(table) < 0.001;
    deleteHashTable(&table);
    return result;
}