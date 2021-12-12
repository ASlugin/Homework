#define _CRT_SECURE_NO_WARNINGS
#include "HashTable.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_WORD 100
#define INITIAL_QUANTITY 15

typedef struct HashTable
{
        List** array;
        int numberOfEntries;
        int numberOfBuckets;
} HashTable;

HashTable* createHashTable(void)
{
    HashTable* hashTable = calloc(1, sizeof(HashTable));
    if (hashTable == NULL)
    {
        return NULL;
    }
    hashTable->numberOfBuckets = INITIAL_QUANTITY;
    hashTable->numberOfEntries = 0;
    hashTable->array = calloc(INITIAL_QUANTITY, sizeof(List*));
    if (hashTable->array == NULL)
    {
        free(hashTable);
        return NULL;
    }
    return hashTable;
}

void deleteArray(List** array, const int arraySize)
{
    if (array == NULL)
    {
        return;
    }
    for (int i = 0; i < arraySize; ++i)
    {
        deleteList(&array[i]);
    }
    free(array);
}

void deleteHashTable(HashTable** hashTable)
{
    if (*hashTable == NULL)
    {
        return;
    }
    deleteArray((*hashTable)->array, (*hashTable)->numberOfBuckets);
    free(*hashTable);
    *hashTable = NULL;
}

int hashFunction(const char word[], int numberOfBuckets)
{
    const int length = strlen(word);
    int hash = 0;
    for (int i = 0; i < length; ++i)
    {
        hash = (hash + word[i]) % numberOfBuckets;
    }
    return hash;
}

float getLoadFactor(HashTable* hashTable)
{
    return (float) hashTable->numberOfEntries / hashTable->numberOfBuckets;
}

bool resizing(HashTable* hashTable)
{
    int oldNumberOfBuckets = hashTable->numberOfBuckets;
    List** oldArray = hashTable->array;
    
    List** newArray = calloc(oldNumberOfBuckets * 2, sizeof(List*));
    if (newArray == NULL)
    {
        return false;
    }
    hashTable->array = newArray;
    hashTable->numberOfBuckets = oldNumberOfBuckets * 2;
    hashTable->numberOfEntries = 0;
    
    for (int i = 0; i < oldNumberOfBuckets; ++i)
    {
        while (!isEmpty(oldArray[i]))
        {
            char word[SIZE_WORD] = {'\0'};
            strcpy(word, getWordFromHead(oldArray[i]));
            int counter = getValueOfCounterFromHead(oldArray[i]);
            
            if (!addToHashTable(hashTable, word, counter))
            {
                deleteArray(newArray, oldNumberOfBuckets * 2);
                return false;
            }
            deleteElementFromHead(oldArray[i]);
        }
        deleteList(&oldArray[i]);
    }
    deleteArray(oldArray, oldNumberOfBuckets);
    return true;
}

bool addToHashTable(HashTable* hashTable, const char word[], const int currentCounter)
{
    const int hash = hashFunction(word, hashTable->numberOfBuckets);
    if (!addToList(&(hashTable->array[hash]), word, currentCounter))
    {
        return false;
    }
    ++hashTable->numberOfEntries;
    return getLoadFactor(hashTable) > 1.2 ? resizing(hashTable) : true; 
}

void printHashTable(HashTable* hashTable)
{
    if (hashTable == NULL)
    {
        return;
    }
    for (int i = 0; i < hashTable->numberOfBuckets; ++i)
    {
        printList(hashTable->array[i]);
    }
}

int getMaximumLength(HashTable* hashTable)
{
    if (hashTable == NULL)
    {
        return 0;
    }
    int maxLength = -1;
    for (int i = 0; i < hashTable->numberOfBuckets; ++i)
    {
        if (getListLength(hashTable->array[i]) > maxLength)
        {
            maxLength = getListLength(hashTable->array[i]);
        }
    }
    return maxLength;
}

float getAvarageLength(HashTable* hashTable)
{
    if (hashTable == NULL)
    {
        return 0;
    }
    int sumLength = 0;
    for (int i = 0; i < hashTable->numberOfBuckets; ++i)
    {
       sumLength += getListLength(hashTable->array[i]);
    }
    return (float) sumLength / hashTable->numberOfBuckets;
}

bool readDataFromFile(HashTable* hashTable, const char name[])
{
    FILE* file = fopen(name, "r");
    if (file == NULL)
    {
        return false;
    }
    while (!feof(file))
    {
        char word[SIZE_WORD] = {'\0'};
        fscanf(file, "%s%*c", word);
        if (!addToHashTable(hashTable, word, 1))
        {
            fclose(file);
            return false;
        }
    }
    fclose(file);
    return true;
}

int getNumberOfOccurrences(HashTable* hashTable, const char word[])
{
    if (hashTable == NULL)
    {
        return 0;
    }
    int hash = hashFunction(word, hashTable->numberOfBuckets);
    return getCounter(hashTable->array[hash], word);
}