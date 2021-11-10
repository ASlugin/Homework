#pragma once

#include <stdbool.h>

// Structure for List, contain amount of element in list, pointer to first and last element
typedef struct List List;

// Creates List and returns pointer to list
// If allocation error, returns NULL
List* createList(void);

// Deletes all element of list and puts in "list" NULL
void deleteList(List** list);

// Returns true if list is empty
// If list doesn't exist, returns true
bool isEmpty(List* list);

// Adds new data to the end of list
// If allocation error, return false
bool add(List* list, const char name[], const char number[]);

// Returns amount of element in list
// If list doesn't exist, returns -1
int getLength(List* list);

// Returns pointer to string containing name in first element of list 
char* getName(List* list);

// Returns pointer to string containing number in first element of list
char* getNumber(List* list);

// Puts in "name" name, in "name" number that are in first element of list, ans deletes first element of list
// If not successful, returns false
bool pop(List* list, char* name, char* number);

// Prints all elements of list in "name - number" format
void printList(List* list);

// Reads data from file and puts their in list
// If not successful, returns NULL
List* readDataFromFile(const char file[]);