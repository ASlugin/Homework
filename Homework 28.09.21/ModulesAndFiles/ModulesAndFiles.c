#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "QuickSort.h"
#include "Tests.h"

int frequentElement(int *array, int amount)
{
    int maxAmountIdenticalElement = 0;
    int countIdentical = 0;
    int element = 0;
    for (int i = 1; i < amount; ++i)
    {
        if (array[i - 1] == array[i])
        {
            ++countIdentical;
            if (countIdentical + 1 > maxAmountIdenticalElement)
            {
                maxAmountIdenticalElement = countIdentical + 1;
                element = array[i - 1];
            }
        }
        else
        {
            countIdentical = 0;
        }
    }
    if (maxAmountIdenticalElement == 0)
    {
        element = array[0];
    }
    return element;
}

int main()
{
    if (!tests())
    {
        printf("%s", "Tests failed!");
        return 0;
    }
    FILE* input = fopen("input.txt", "r");
    if (input == NULL)
    {
        printf("%s", "File not found!");
        return 0;
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
        return 0;
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