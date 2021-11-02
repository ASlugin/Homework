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

void deletePosition(Position** index);

// Deletes list
void deleteList(List** list);

// Returns true if list is empty, else returns false
bool isEmpty(List* list);

// Adds value to list so that list stay sorted. If allocation error, returns false, else true.
bool add(List* list, int value);

// Removes all elements with the value "value" from the list
void deleteValue(List* list, int value);

// Prints all elements of list
void printList(List* list);

// Retuns pointer to Position containing pointer to first element of list. If List doesn't exist, returns NULL.
Position* first(List* list, Position* index);

// Returns pointer to Position containing pointer to next element in list. If "index" doesn't point to nothing, returns NULL.
Position* next(Position* index);

// Returns true if "index" doesn't point to element, else returns false.
bool isThereNoElement(Position* index);

// Returns value of element that "index" point to. If "index" doesn't point to element, returns 0.
int get(Position* index);