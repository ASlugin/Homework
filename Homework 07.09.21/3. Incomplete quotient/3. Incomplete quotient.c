#include <stdio.h>
#include <math.h>

int main()
{
    int dividend = 0;
    int divisor = 0;
    printf("%s", "Enter dividend and divisor: ");
    scanf("%d %d", &dividend, &divisor);
    if (divisor == 0)
    {
        printf("%s", "Error: cannot divide by zero");
        return 0;
    }
    int quotient = 0;
    while (abs(dividend) - abs(quotient * divisor) >= abs(divisor))
    {
        quotient++;
    }
    if (dividend > 0 && divisor < 0)
    {
        quotient *= -1;
    }
    if (dividend < 0)
    {
        if (dividend < abs(divisor * quotient) * -1)
        {
            quotient++;
        }
        if (divisor > 0)
        {
            quotient = -quotient;
        }
    }

    printf("%s %d", "Incomplete quotient:", quotient);
    return 0;
}