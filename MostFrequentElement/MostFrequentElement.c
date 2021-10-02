#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
        }
        else
        {
            if (countIdentical + 1 > maxAmountIdenticalElement)
            {
                maxAmountIdenticalElement = countIdentical + 1;
                element = array[i - 1];
            }
            countIdentical = 0;
        }
    }
    if (countIdentical + 1 > maxAmountIdenticalElement)
    {
        element = array[amount - 1];
    }
    return element;
}

bool tests()
{
    #define SIZE 3
    int enteredArray[SIZE][10] = {{4, 1, 7, 8, 3, 0, 0, 0, 0, 0}, {4, 9 ,7, 9, 9, 4, 3, 0, 0, 0}, {3, 1, 4, 9, 1, 3, 4, 9, 4, 7}};
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

int main()
{
    if (!tests())
    {
        printf("%s", "Tests failed!");
        return 0;
    }
    int amount = 0;
    printf("%s ", "Enter amount of array elements:");
    scanf("%d", &amount);
    if (amount <= 0)
    {
        printf("%s", "Incorrect amount");
        return 0;
    }
    int *array = calloc(amount, sizeof(int));
    printf("%s ", "Enter array elements:");
    for (int i = 0; i < amount; ++i)
    {
        scanf("%d", &array[i]);
    }
    quickSort(array, 0, amount - 1);

    const int result = frequentElement(array, amount);
    printf("%s%d", "Most frequent element: ", result);

    free(array);
    return 0;
}