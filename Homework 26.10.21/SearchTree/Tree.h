#pragma once

#include <stdbool.h>

typedef struct Tree Tree;

// Creates tree, if allocation error, returns NULL
Tree* createTree();

// Returns true if tree is empty ot doesn't exist
bool isEmpty(Tree* tree);

// Deletes all elements of tree and puts to "tree" NULL
void deleteTree(Tree** tree);

// Returns pointer to value for specified key without control. If there is no such key, returns NULL.
char* getValueByKey(Tree* tree, const int key);

// Returns true if tree contain key, else return false
bool treeContainThisKey(Tree* tree, const int key);

// Adds a value by the specified key to the tree. If such a key already exists, the value is replaced with a new one.
// Accepts "value" without control. If not successfully, returns false.
bool add(Tree* tree, const int key, const char value[]);

// Deletes node by key. If not successfully, returns false.
bool deleteNodeByKey(Tree* tree, const int key);