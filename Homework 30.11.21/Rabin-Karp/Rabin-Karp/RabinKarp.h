#pragma once

// Searches for searchString in file and returns position of first occurrence
// If file not found returns -2
// If searchString not found in file returns -1
int rabinKarpSearchInFile(const char searchString[], const char nameFile[]);

// Returns position of first occurrence searchString in string
// Returns -1 if searchString not found in string
int rabinKarpSearchInString(const char searchString[], const char string[]);