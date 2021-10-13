#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void firstElementInPlace(int* array, int amount)
{
    int left = 1;
    int right = amount - 1;
    while (right > left)
    {
        while (array[left] < array[0] && left < right)
        {
            left++;
        }
        while (array[right] >= array[0] && left < right)
        {
            right--;
        }
        if (right > left && array[left] >= array[0] && array[right] < array[0])
        {
            const int temp = array[left];
            array[left] = array[right];
            array[right] = temp;
        }
    }
    const int temp = array[left - 1];
    array[left - 1] = array[0];
    array[0] = temp;
}

bool tests()
{
    #define AMOUNTTESTS 3
    int array[AMOUNTTESTS][10] = 
    {
        {79, 87, 26, 29, 7, 12, 43, 51, 65, 22},
        {35, 69, 5, 22, 15, 31, 19, 23, 18, 8},
        {58, 4, 82, 25, 81, 50, 6, 0, 27, 8}
    };
    const int result[AMOUNTTESTS][10] =
    {
        {65, 22, 26, 29, 7, 12, 43, 51, 79, 87},
        {18, 8, 5, 22, 15, 31, 19, 23, 35, 69},
        {0, 4, 8, 25, 27, 50, 6, 58, 81, 82}
    };
    for (int i = 0; i < AMOUNTTESTS; ++i)
    {
        firstElementInPlace(array[i], 10);
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

int main()
{
    if (!tests())
    {
        printf("%s", "Tests failed!");
        return 0;
    }
    srand(time(NULL));
    #define SIZE 10
    int array[SIZE] = {0};
    for (int i = 0; i < SIZE; ++i)
    {
        array[i] = rand() % 100;
        printf("%d ", array[i]);
    }
    printf("\n");

    firstElementInPlace(array, SIZE);
    for (int i = 0; i < SIZE; ++i)
    {
        printf("%d ", array[i]);
    }
    return 0;
}
