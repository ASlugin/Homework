﻿#define _CRT_SECURE_NO_WARNINGS
#include "TwoDimensionalArray.h"
#include <stdio.h>

int main(int argc, char* argv[])
{
    if (argc > 1)
    {
        return 1;
    }
    int numberOfRows = 0;
    int numberOfColumns = 0;
    printf("Enter number of rows: ");
    scanf("%d", &numberOfRows);
    printf("Enter number of columns: ");
    scanf("%d", &numberOfColumns);
    
    TwoDimensionalArray* array = createArray(numberOfRows, numberOfColumns);

    return 0;
}