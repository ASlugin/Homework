#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int partition(int* array, int left, int right)
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

void quickSort(int* array, int left, int right)
{
    if (left < right)
    {
        const int elementInRightPlace = partition(array, left, right);
        quickSort(array, left, elementInRightPlace - 1);
        quickSort(array, elementInRightPlace + 1, right);
    }
}

bool binarySearch(int *array, int left, int right, int number)
{
    const int middle = (right + left) / 2;
    if (right < left)
    {
        return false;
    }
    if (number == array[middle])
    {
        return true;
    }
    if (left == right)
    {
        return false;
    }

    if (number < array[middle])
    {
        return binarySearch(array, left, middle - 1, number);
    }
    return binarySearch(array, middle + 1, right, number);
}

bool tests()
{
    #define SIZE 5
    #define SIZEARRAY 10
    int array[SIZEARRAY] = {12, 34, 2, 5, 78, 97, 14, 16, 4, 3};
    const int number[SIZE] = {5, 45, 67, 12, 97};
    bool result[SIZE] = {true, false, false, true, true};
    quickSort(array, 0, SIZEARRAY - 1);
    for (int i = 0; i < SIZE; ++i)
    {
        if (binarySearch(array, 0, SIZEARRAY - 1, number[i]) != result[i])
        {
            return false;
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

    int n = 0;
    printf("%s ", "Enter value \"n\":");
    scanf("%d", &n);
    int k = 0;
    printf("%s ", "Enter value \"k\":");
    scanf("%d", &k);
    
    srand((unsigned)time(NULL));
    int *array = malloc(n * sizeof(int));
    if (array == NULL)
    {
        printf("%s", "Allocation error");
        return -1;
    }
    printf("%s ", "Array of random numbers:");
    for (int i = 0; i < n; ++i)
    {
        array[i] = rand() % 100;
        printf("%d ", array[i]);
    }
    printf("\n");
    quickSort(array, 0, n - 1);
    
    for (int i = 0; i < k; ++i)
    {
        int randomNumber = rand() % 100;
        if (binarySearch(array, 0, n - 1, randomNumber))
        {
            printf("%s%d%s\n", "\"", randomNumber, "\" is contained in array");
        }
        else
        {
            printf("%s%d%s\n", "\"", randomNumber, "\" is not contained in array");
        }
    }
    free(array);
    return 0;
}