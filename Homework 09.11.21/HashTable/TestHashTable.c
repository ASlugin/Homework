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

    bool result = abs((int)(0.93 - getLoadFactor(table)) * 100) < 1 && getMaximumLength(table) == 3 && abs((int)(0.73 - getAverageLength(table)) * 100) < 1;
    deleteHashTable(&table);
    return result;
}