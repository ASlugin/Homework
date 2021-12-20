#include "TwoDimensionalArray.h"
#include <stdlib.h>

typedef struct TwoDimensionalArray
{
    int** array;
} TwoDimensionalArray;

TwoDimensionalArray* createArray(int numberOfRows, int numberOfColumns)
{
    int** array = (int**) calloc(numberOfRows, sizeof(*array));
    if (array == NULL)
    {
        return NULL;
    }
    for (int i = 0; i < numberOfRows; ++i)
    {
        array[i] = (int*) calloc(numberOfRows, sizeof(*array[i]));
    }

    return array;
}