#pragma once

#include <stdbool.h>

// Structure for hash table
typedef struct HashTable HashTable;

// Creates and returns pointer to hash table
HashTable* createHashTable(void);

// Deletes hash table and puts NULL to hashTable
void deleteHashTable(HashTable** hashTable);

// Returns load factor of hash table
float getLoadFactor(HashTable* hashTable);

// Adds word to hash table
// If need to add a new word, currentCounter must be 1
bool addToHashTable(HashTable* hashTable, const char word[], const int currentCounter);

// Prints all elements of list
void printHashTable(HashTable* hashTable);

// Returns maximum length of list in hash table
int getMaximumLength(HashTable* hashTable);

// Returns avarege length of lists in hash table
float getAverageLength(HashTable* hashTable);

// Reads data from file and puts them to hash table
// Returns true if reading is success, else returns false
bool readDataFromFile(HashTable* hashTable, const char name[]);

// Returns number of occurrences given word to hash table
int getNumberOfOccurrences(HashTable* hashTable, const char word[]);