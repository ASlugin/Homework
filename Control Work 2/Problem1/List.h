#pragma once

#include <stdbool.h>

// Structure containing pointer to first element of list
typedef struct List List;

// Structure containing pointer to element of list
typedef struct Position Position;

// Creates new List. If allocation error, returns NULL.
List* createList();

// Creates new Position. If allocation error, returns NULL.
Position* createPosition();

// Deletes list
void deleteList(List** list);

// Returns true if list is empty, else returns false
bool isEmpty(List* list);

// Adds value to end of list. If position doesn't point to element, adds value to first element;
bool add(List* list, Position* position, int value);

// Creates list and reads data from file and puts them to list
List* createListAndReadDataFromFile(const char name[]);

// Swaps elements of list
bool swapList(List* list);

// Prints all elements of list
void printList(List* list);