#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swapArray(int array[], int start, int end)
{
    for (int i = start; i <= (end + start) / 2; ++i)
    {
        const int temp = array[i];
        array[i] = array[end - i + start];
        array[end - i + start] = temp;
    }
}

int main(int argc, char* argv[])
{
    if (argc > 1)
    {
        return 1; //without tests
    }
    int m = 0;
    printf("%s\n", "(m + n <= 100)");
    printf("%s", "Enter value \"m\": ");
    scanf("%d", &m);
    int n = 0;
    printf("%s", "Enter value \"n\": ");
    scanf("%d", &n);
    int x[101] = { 0 };
    printf("%s", "Enter array elements \"x\": ");
    for (int i = 0; i < m + n; ++i)
    {
        scanf("%d", &x[i]);
    }

    swapArray(x, 0, m - 1);
    swapArray(x, m, m + n - 1);
    swapArray(x, 0, m + n - 1);

    printf("%s", "Result: ");
    for (int i = 0; i < m + n; ++i)
    {
        printf("%d ", x[i]);
    }
    return 0;
}
