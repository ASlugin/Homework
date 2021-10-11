#include <stdio.h>
#include <stdbool.h>
#include <math.h>

double exponentiation(int number, int power)
{
    int result = 1;
    const int absPower = abs(power);
    for (int i = 0; i < absPower; ++i)
    {
        result = result * number;
    }
    if (power < 0)
    {
        return (double) 1 / result;
    }
    return (double) result;
}

bool tests()
{
    #define SIZE 8
    const int enterNumber[SIZE] = {-4, 2, 0, 1, 2, 2, 5, 10};
    const int enterPower[SIZE] = {3, 3, 0, -3, -1, -2, -3, -1};
    const double results[SIZE] = {-64, 8, 1, 1, 0.5, 0.25, 0.008, 0.1};
    for (int i = 0; i < SIZE; ++i)
    {
        if (results[i] != exponentiation(enterNumber[i], enterPower[i]))
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
    int enteredNumber = 0;
    printf("%s", "Enter number: ");
    scanf("%d", &enteredNumber);
    int enteredPower = 0;
    printf("%s", "Enter power of number: ");
    scanf("%d", &enteredPower);

    const double result = exponentiation(enteredNumber, enteredPower);
    printf("%lf", result);
    return 0;
}