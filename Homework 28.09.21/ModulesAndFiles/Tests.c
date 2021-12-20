#include "Tests.h"
#include "QuickSort.h"

bool tests()
{
    #define SIZE 3
    int enteredArray[SIZE][10] =
    {
        {4, 1, 7, 8, 3, 0, 0, 0, 0, 0},
        {4, 9 ,7, 9, 9, 4, 3, 0, 0, 0},
        {3, 1, 4, 9, 1, 3, 4, 9, 4, 7}
    };
    const int results[SIZE] = {1, 9, 4};
    const int amount[SIZE] = {5, 7, 10};
    for (int i = 0; i < SIZE; ++i)
    {
        quickSort(enteredArray[i], 0, amount[i] - 1);
        const int result = frequentElement(enteredArray[i], amount[i]);
        if (result != results[i])
        {
            return false;
        }
    }
    return true;
}