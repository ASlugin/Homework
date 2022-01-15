#pragma once

#include <stdbool.h>

// Structure for list
typedef struct List List;

typedef struct Position Position;

// Creates list and returns pointer to list
List* createList();

Position* createPosition();

void deletePosition(Position** index);

Position* first(List* list, Position* index);

Position* next(Position* index);

// Deletes list and puts NULL to list
void deleteList(List** list);

// Adds new string to list, if there is not such string
bool add(List* list, const char newString[]);

// Creates list and reads strings from file
// Returns pointer to list
List* CreateListAndReadDataFromFile(const char name[]);

// Deletes repeating string from list
List* deleteRepeatingString(List* list);

// Prints all eements of list
void printList(List* list);