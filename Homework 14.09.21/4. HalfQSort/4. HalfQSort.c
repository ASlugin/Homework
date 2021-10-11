#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void elementInPlace(int* array, int amount)
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

int main()
{
    srand(time(NULL));
#define SIZE 10
    int array[SIZE] = { 0 };
    for (int i = 0; i < SIZE; ++i)
    {
        array[i] = rand() % 100;
        printf("%d ", array[i]);
    }
    printf("\n");

    elementInPlace(array, SIZE);
    for (int i = 0; i < SIZE; ++i)
    {
        printf("%d ", array[i]);
    }
    return 0;
}
