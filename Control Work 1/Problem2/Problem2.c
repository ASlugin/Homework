#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void selectionSort(int *array, int amount)
{
    for (int i = 0; i < amount; ++i)
    {
        int indexMin = i;
        for (int j = i + 1; j < amount; ++j)
        {
            if (array[j] < array[indexMin])
            {
                indexMin = j;
            }
        }
        const int temp = array[i];
        array[i] = array[indexMin];
        array[indexMin] = temp;
    }
}

bool tests()
{
    #define AMOUNTTESTS 3
    int array[AMOUNTTESTS][10] = 
    {
        {9, 8, 7, 6, 5, 4, 3, 2, 1, 0},
        {15, 64, 32, 14, 62, 15, 12, 7, 45, 3},
        {32, 12, 14, 12, 65, 9, 7, 6, 16, 17}
    };
    int result[AMOUNTTESTS][10] =
    {
        {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
        {3, 7, 12, 14, 15, 15, 32, 45, 62, 64},
        {6, 7, 9, 12, 12, 14, 16, 17, 32, 65}
    };
    
    for (int i = 0; i < AMOUNTTESTS; ++i)
    {
        selectionSort(array[i], 10);
        for (int j = 0; j < 10; ++j)
        {
            if (array[i][j] != result[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

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
    const int amount = 10;
    int *array = calloc(amount, sizeof(10));
    if (array == NULL)
    {
        printf("%s", "Allocation error");
        return 0;
    }
    printf("%s%d%s", "Enter ", amount, " array elements: ");
    for (int i = 0; i < amount; ++i)
    {
        scanf("%d", &array[i]);
    }
    
    selectionSort(array, amount);
    for (int i = 0; i < amount; ++i)
    {
        printf("%d ", array[i]);
    }

    free(array);
    return 0;
}