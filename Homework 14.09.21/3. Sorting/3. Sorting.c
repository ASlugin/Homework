#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void bubbleSort(int *array, int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = n - 1; j > i; --j)
        {
            if (array[j - 1] > array[j])
            {
                const int temp = array[j - 1];
                array[j - 1] = array[j];
                array[j] = temp;
            }
        }
    }
}

void countSort(int *array, int n)
{
    int minElement = array[0];
    int maxElement = array[0];
    for (int i = 0; i < n; ++i)
    {
        if (array[i] < minElement)
        {
            minElement = array[i];
        }
        if (array[i] > maxElement)
        {
            maxElement = array[i];
        }
    }
    int *arrayCount = calloc(maxElement - minElement + 1 , sizeof(int));
    for (int i = 0; i < n; ++i)
    {
        ++arrayCount[array[i] - minElement];
    }
    int position = 0;
    for (int i = 0; i < maxElement - minElement + 1; ++i)
    {
        for (int j = 0; j < arrayCount[i]; ++j)
        {
            array[position] = i + minElement;
            position++;
        }
    }
    free(arrayCount);
}

float differenceClock()
{
    srand((unsigned int)time(NULL));
    int *bigArrayForBubbleSort = malloc((100000) * sizeof(int));
    int *bigArrayForCountSort = malloc((100000) * sizeof(int));
    for (int i = 0; i < 100000; ++i)
    {
        bigArrayForBubbleSort[i] = rand() % 10000;
        bigArrayForCountSort[i] = bigArrayForBubbleSort[i];
    }

    const clock_t startBubbleSort = clock();
    bubbleSort(bigArrayForBubbleSort, 100000);
    const clock_t stopBubbleSort = clock();
    const float timeBubbleSort = (float) (stopBubbleSort - startBubbleSort) / CLK_TCK;
    
    const clock_t startCountSort = clock();
    countSort(bigArrayForCountSort, 100000);
    const clock_t stopCountSort = clock();
    const float timeCountSort = (float) (stopCountSort - startCountSort) / CLK_TCK;
    
    const float difference = timeBubbleSort - timeCountSort;
    free(bigArrayForBubbleSort);
    free(bigArrayForCountSort);
    return difference;
}

bool checkRightSort(int *array, int *result, int amount)
{
    for (int i = 0; i < amount; ++i)
    {
        if (array[i] != result[i])
        {
            return false;
        }
    }
    return true;
}

bool tests()
{
    int amount[3] = {3, 5, 10};
    int arrayBubbleSort[3][10] = {{9, 4, 7, 0, 0, 0, 0, 0, 0, 0}, {4, 7, 3, 5, 9, 0, 0, 0, 0, 0}, {9, 8, 7, 8, 12, 0, 3, 4, 9, 5}};
    int arrayCountSort[3][10] = {{9, 4, 7, 0, 0, 0, 0, 0, 0, 0}, {4, 7, 3, 5, 9, 0, 0, 0, 0, 0}, {9, 8, 7, 8, 12, 0, 3, 4, 9, 5}};
    int results[3][10] = {{4, 7, 9, 0, 0, 0, 0, 0, 0, 0}, {3, 4, 5, 7, 9, 0, 0, 0, 0, 0}, {0, 3, 4, 5, 7, 8, 8, 9, 9, 12}};
    for (int i = 0; i < 3; ++i)
    {
        bubbleSort(arrayBubbleSort[i], amount[i]);
        if (!checkRightSort(arrayBubbleSort[i], results[i], amount[i]))
        {
            return false;
        }
        countSort(arrayCountSort[i], amount[i]);
        if (!checkRightSort(arrayCountSort[i], results[i], amount[i]))
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
        return 0;
    }
    if (argc > 1)
    {
        return 0;
    }
    #define SIZE 100
    int amount = 0;
    printf("%s", "Enter amount of elemets <= 100: ");
    scanf("%d", &amount);
    int enteredArray[SIZE] = {0};
    int arrayBubble[SIZE] = {0};
    int arrayCount[SIZE] = {0};
    printf("%s", "Enter array elements: ");
    for (int i = 0; i < amount; ++i)
    {
        scanf("%d", &enteredArray[i]);
        arrayBubble[i] = enteredArray[i];
        arrayCount[i] = enteredArray[i];
    }
    bubbleSort(arrayBubble, amount);
    printf("%s", "Array after bubble sort: ");
    for (int i = 0; i < amount; ++i)
    {
        printf("%d ", arrayBubble[i]);
    }
    countSort(arrayCount, amount);
    printf("\n");
    printf("%s", "Array after count sort: ");
    for (int i = 0; i < amount; ++i)
    {
        printf("%d ", arrayCount[i]);
    }
    printf("\n");
    const float difference = differenceClock();
    printf("%s %f %s", "Bubble sort longer than Count sort on 100000 elements by", difference, "seconds");
    return 0;
}
