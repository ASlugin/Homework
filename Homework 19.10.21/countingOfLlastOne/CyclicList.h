#pragma once

#include <stdbool.h>

// Structure for pointer to list
typedef struct List List;

// Structur for pointer to element of list
typedef struct Position Position;

// Creates List and returns pointer to List
// If allocation error, returns NULL
List* createList();

// Creates Position and returns pointer to Position
// If allocation error, returns NULL
Position* createPosition();

// Deletes Position pointed by "index" and puts in "index" NULL
void deletePosition(Position** index);

// Returns true if list is empty, else returns false
bool isEmpty(List* list);

// Returns pointer to Position that point to first element of list
Position* first(List* list, Position* index);

// Returns pointer to Position that point to next element of list.
// If "index" doesn't point to element, returns NULL.
Position* next(Position* index);

// Returns pointer to Position that point to last element of list
// If List "list" or Position "index" doesn't exist, returns NULL
Position* last(List* list, Position* index);

// Ñopies pointer to element from Position "from" to Position "toThere"
void copyPosition(Position* from, Position* toThere);

// Returns true if in list left only one element
bool isOneElementLeft(List* list);

// Adds new element with value "value" to list after element that "afterWhichAdd" point to.
// If "addWhichAdd" doesn't point to element and list is not empty, returns false.
bool add(List* list, Position* afterWhichAdd, int value);

// Deletes element of list pointed by "index"
// If Position "index" or List "list" doesn't exist or list is empty or "index" doesn't point to element, returns false.
bool deleteElement(List* list, Position* index);

// Deletes List
void deleteList(List** list);

// Retunrs value of element pointed by "index"
// If "index" doesn't point to element, returns 0
int get(Position* index);