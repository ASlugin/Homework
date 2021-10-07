#include <stdio.h>
#include <math.h>

int main()
{
    int maxNumber = 0;
    printf("%s", "Enter numder: ");
    scanf("%d", &maxNumber);
    printf("%s %d: ", "All prime numbers less than", maxNumber);
    for (int i = 1; i <= maxNumber; ++i)
    {
        int countDivisor = 0;
        for (int j = 2; j <= round(sqrt(i)); ++j)
        {
            if (i % j == 0)
            {
                countDivisor++;
            }
        }
        if (countDivisor == 0)
        {
            printf("%d ", i);
        }
    }
    return 0;
}
