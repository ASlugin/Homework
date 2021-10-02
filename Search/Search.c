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
    if (right < left)
    {
        return false;
    }
    if (number == array[(right + left) / 2])
    {
        return true;
    }
    if (left == right)
    {
        return false;
    }

    if (number < array[(right + left) / 2])
    {
        return binarySearch(array, left, (right + left) / 2 - 1, number);
    }
    return binarySearch(array, (right + left) / 2 + 1, right, number);
}

int main()
{
    int n = 0;
    printf("%s ", "Enter value \"n\":");
    scanf("%d", &n);
    int k = 0;
    printf("%s ", "Enter value \"k\":");
    scanf("%d", &k);
    
    srand((int) time(NULL));
    int *array = malloc(n * sizeof(int));
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
            printf("%s%d%s\n", "\"",randomNumber, "\" is contained in array");
        }
        else
        {
            printf("%s%d%s\n", "\"", randomNumber, "\" is not contained in array");
        }
    }
    free(array);
    return 0;
}