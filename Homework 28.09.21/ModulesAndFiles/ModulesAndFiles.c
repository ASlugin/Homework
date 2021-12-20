#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "QuickSort.h"
#include "Tests.h"

int main(int argc, char* argv[])
{
    if (!tests())
    {
        if (argc <= 1)
        {
            printf("%s", "Tests failed!");
        }
        return -1;
    }
    if (argc > 1)
    {
        return 0;
    }

    FILE* input = fopen("input.txt", "r");
    if (input == NULL)
    {
        printf("%s", "File not found!");
        return -1;
    }

    int amount = 0;
    fscanf(input, "%d", &amount);
    if (amount <= 0)
    {
        printf("%s", "Incorrect amount");
        fclose(input);
        return 0;
    }

    int *array = calloc(amount, sizeof(int));
    if (array == NULL)
    {
        printf("%s", "Allocation error");
        fclose(input);
        return -1;
    }
    for (int i = 0; i < amount; ++i)
    {
        fscanf(input, "%d", &array[i]);
    }
    fclose(input);

    quickSort(array, 0, amount - 1);
    printf("%s%d", "Most frequent element: ", frequentElement(array, amount));

    free(array);
    return 0;
}