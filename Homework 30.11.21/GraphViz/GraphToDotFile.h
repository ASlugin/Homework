#pragma once

#include <stdbool.h>

// Creates a dot file and generates a graph based on the adjacency matrix in input file
// Returns true if successful
bool generateDotFile(const char nameInputFile[], const char nameDotFile[]);