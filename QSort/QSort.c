#include <stdio.h>
#include <stdbool.h>

void insertionSort(int* array, int left, int right)
{
    for (int i = left + 1; i <= right; ++i)
    {
        int position = i;
        while (position > left && array[position] < array[position - 1])
        {
            const int temp = array[position];
            array[position] = array[position - 1];
            array[position - 1] = temp;
            --position;
        }
    }
}

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
    if (right - left + 1 >= 10)
    {
        const int elementInRightPlace = partition(array, left, right);
        quickSort(array, left, elementInRightPlace - 1);
        quickSort(array, elementInRightPlace + 1, right);
    }
    else if (left < right)
    {
        insertionSort(array, left, right);
    }
}

bool tests()
{
#define SIZETESTS 3
    int enteredArray[SIZETESTS][20] = {{48, 50, 79, 18, 50, 40, 15, 51, 47, 26, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {98, 57, 31, 18, 0, 61, 48, 68, 49, 27, 38, 34, 98, 15, 79, 76, 2, 11, 71, 77}, {50, 24, 46, 83, 93, 53, 79, 0, 90, 62, 71, 39, 72, 12, 6, 0, 0, 0, 0, 0}};
    const int result[SIZETESTS][20] = {{15, 18, 26, 40, 47, 48, 50, 50, 51, 79, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 2, 11, 15, 18, 27, 31, 34, 38, 48, 49, 57, 61, 68, 71, 76, 77, 79, 98, 98}, {0, 6, 12, 24, 39, 46, 50, 53, 62, 71, 72, 79, 83, 90, 93, 0, 0, 0, 0, 0}};
    const int amount[SIZETESTS] = {10, 20, 15};
    for (int i = 0; i < SIZETESTS; ++i)
    {
        quickSort(enteredArray[i], 0, amount[i] - 1);
        for (int j = 0; j < amount[i]; ++j)
        {
            if (enteredArray[i][j] != result[i][j])
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
#define SIZE 100
    int array[SIZE] = {0};
    int amount = 0;
    printf("%s ", "Enter amount of array elements <= 100:");
    scanf("%d", &amount);
    printf("%s ", "Enter array elements:");
    for (int i = 0; i < amount; ++i)
    {
        scanf("%d", &array[i]);
    }
    quickSort(array, 0, amount - 1);
    for (int i = 0; i < amount; ++i)
    {
        printf("%d ", array[i]);
    }
    return 0;
}