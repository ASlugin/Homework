#include <stdio.h>
#include <stdbool.h>
#include <math.h>

double exponentiation(int number, int power)
{
    if (power < 0)
    {
        return (double) 1 / exponentiation(number, abs(power));
    }
    else if (power == 0)
    {
        return 1;
    }
    else if (power == 1)
    {
        return number;
    }
    else if (power % 2 == 0)
    {
        double result = exponentiation(number, power / 2);
        return result * result;
    }
    else
    {
        return exponentiation(number, power - 1) * number;
    }
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