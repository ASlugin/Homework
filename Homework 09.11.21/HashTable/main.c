#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "HashTable.h"
#include "TestHashTable.h"

int main(void)
{
    if (!isTestHashTablePassing())
    {
        printf("Test of hash table failed!\n");
        return -1;
    }

    HashTable* table = createHashTable();
    if (table == NULL)
    {
        return -1;
    }
    if (!readDataFromFile(table, "Input.txt"))
    {
        deleteHashTable(&table);
        return -1;
    }

    printHashTable(table);
    printf("Load factor of hash table: %.2f\n", getLoadFactor(table));
    printf("Maximum length of list in hash table: %d\n", getMaximumLength(table));
    printf("Avarage length of list in hash table: %.2f\n", getAvarageLength(table));

    deleteHashTable(&table);
    return 0;
}