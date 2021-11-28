#pragma once

#include <stdbool.h>

// Structure for tree. It contains pointer to root of tree
typedef struct Tree Tree;

// Creates tree. If allocation is error, returns NULL
Tree* createTree(void);

// Returns true if tree is empty or doesn't exist
bool isEmpty(Tree* tree);

// Deletes tree. Takes control of "tree" and after deletion puts to "tree" NULL
void deleteTree(Tree** tree);

// Returns true if there is key in tree
bool treeContainThisKey(Tree* tree, const int key);

// Adds data to tree. Doesn't take control of value.
// If such key already exist, replaces value with new value.
// Returns true if the addition was successful.
bool add(Tree* tree, const int key, const char value[]);

// Deletes node with given key
void deleteNodeByKey(Tree* tree, const int key);

// Returns pointer to value by given key. If there is not key in tree, returns NULL
char* getValueByKey(Tree* tree, const int key);