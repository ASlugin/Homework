#pragma once

#include <stdbool.h>

typedef struct Tree Tree;

// Creates tree and reads expression from File with name file
Tree* createTreeAndReadFromFile(const char fileName[]);

// Deletes all nodes of tree and puts NULL to "tree"
void deleteTree(Tree** tree);

// Prints expression that contained in tree
void printTree(Tree* tree);

// Calculates expression that contained in tree
int calculate(Tree* tree);