#include "QuickSort.h"

int partition(int *array, int left, int right)
{
    const int pivot = array[right];
    int i = left;
    for (int j = left; j < right; ++j)
    {
        if (array[j] <= pivot)
        {
            const int temp = array[j];
            array[j] = array[i];
            array[i] = temp;
            ++i;
        }
    }
    array[right] = array[i];
    array[i] = pivot;
    return i;
}

void quickSort(int *array, int left, int right)
{
    if (left < right)
    {
        const int elementInRightPlace = partition(array, left, right);
        quickSort(array, left, elementInRightPlace - 1);
        quickSort(array, elementInRightPlace + 1, right);
    }
}

int frequentElement(int* array, int amount)
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