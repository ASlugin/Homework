#include <stdio.h>
#include <stdbool.h>

int fibonacci(int number)
{
    if (number < 0)
    {
        return -1;
    }
    else if (number == 0)
    {
        return 0;
    }
    else if (number == 1)
    {
        return 1;
    }
    int fibonacci0 = 0;
    int fibonacci1 = 1;
    int result = 0;
    for (int i = 0; i < number-1; ++i)
    {
        result = fibonacci0 + fibonacci1;
        fibonacci0 = fibonacci1;
        fibonacci1 = result;
    }
    return result;
}

bool test()
{
    #define SIZE 8
    int enterNumber[SIZE] = {-10, -2, 0, 1, 3, 6, 10, 12};
    int result[SIZE] = {-1, -1, 0, 1, 2, 8, 55, 144};
    for (int i = 0; i < SIZE; ++i)
    {
        if (fibonacci(enterNumber[i]) != result[i])
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
        printf("%s", "Tests failed");
        return 0;
    }
    int numberFibonacci = -1;
    printf("%s", "Enter fibonacci number: ");
    scanf("%d", &numberFibonacci);
    const int result = fibonacci(numberFibonacci);
    if (result == -1)
    {
        printf("%s", "Incorrect fibonacci number");
        return 0;
    }
    printf("%d %s %d", numberFibonacci, "fibonacci number:", result);
    return 0;
}