#pragma once

#include "List.h"
#include <stdbool.h>

// Sorts list by name, if code is 0, or by number phone, if code is 1
// If not succesful, returns false, else, returns true
bool mergeSort(List* list, const int code);