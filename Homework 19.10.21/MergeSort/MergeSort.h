#pragma once

#include "List.h"
#include <stdbool.h>

// Enumeration to specify key by which the data should be sorted
typedef enum SortBy
{
    name,
    number
} SortBy;

// Sorts list by key
// If not succesful, returns false, else, returns true
bool mergeSort(List* list, SortBy key);