#pragma once

#include <stdbool.h>

// Structure for list
typedef struct List List;

// Creates new List. If allocation error, returns NULL.
List* createList();

// Deletes list
void deleteList(List** list);

// Returns true if list is empty or doesn't exist, else returns false
bool isEmpty(List* list);

// Adds word to list
bool addToList(List** list, const char newWord[], const int currentCounter);

// Returns pointer to word from first element of list
char* getWordFromHead(List* list);

// Returns value of counter from first element of list
int getValueOfCounterFromHead(List* list);

// Deletes first element of list
void deleteElementFromHead(List* list);

// Prints all elements of list in format "word counter\n"
void printList(List* list);

// Returns length of list
int getListLength(List* list);

// Returns counter for given word
int getCounter(List* list, const char word[]);