#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int sumDigits(int number)
{
    number = abs(number);
    int sum = 0;
    while (number > 0)
    {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}

int elementsMaxSumDigits(int *array, int  amount, int *arrayResult)
{
    int max = sumDigits(array[0]);
    int count = 0;
    for (int i = 0; i < amount; ++i)
    {
        const int sumNowElement = sumDigits(array[i]);
        if (sumNowElement > max)
        {
            arrayResult[0] = array[i];
            count = 1;
            max = sumNowElement;
        }
        else if (sumNowElement == max) 
        {
            arrayResult[count] = array[i];
            ++count;
        }
    }
    return count;
}

bool test()
{
    int array[10] = {12, 34, 45, 54, 67, 13, 98, 4, 89, 46};
    const int result[2] = {98, 89};
    const int amountResult = 2;
    
    int arrayElementsMaxSum[10] = {0};
    const int amount = elementsMaxSumDigits(array, 10, arrayElementsMaxSum);
    if (amount != amountResult)
    {
        return false;
    }
    for (int i = 0; i < amount; ++i)
    {
        if (arrayElementsMaxSum[i] != result[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    if (!test())
    {
        printf("%s", "Tests failed!");
        return 0;
    }
    int amount = 0;
    printf("%s", "Enter amount of array elements: ");
    scanf("%d", &amount);
    int *array = calloc(amount, sizeof(int));
    if (array == NULL)
    {
        printf("%s", "Allocation error");
        return 0;
    }
    printf("%s", "Enter array elements: ");
    for (int i = 0; i < amount; ++i)
    {
        scanf("%d", &array[i]);
    }
    int *arrayElementsWithMaxSumDigits = calloc(amount, sizeof(int));
    if (arrayElementsWithMaxSumDigits == NULL)
    {
        printf("%s", "Allocation error");
        free(array);
        return 0;
    }

    const int amountElements = elementsMaxSumDigits(array, amount, arrayElementsWithMaxSumDigits);
    printf("%s", "Elements with max sum  digits: ");
    for (int i = 0; i < amountElements; ++i)
    {
        printf("%d ", arrayElementsWithMaxSumDigits[i]);
    }
    
    free(array);
    free(arrayElementsWithMaxSumDigits);
    return 0;
}