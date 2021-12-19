#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(int argc, char* argv[])
{
    if (argc > 1)
    {
        return 1; //without tests
    }
    int sumCount[28] = { 0 };
    for (int i = 0; i < 1000; ++i)
    {
        int n = i;
        int sum = 0;
        while (n > 0)
        {
            sum = sum + n % 10;
            n = n / 10;
        }
        sumCount[sum]++;
    }
    int count = 0;
    for (int i = 0; i < 28; ++i)
    {
        sumCount[i] = sumCount[i] * sumCount[i];
        count += sumCount[i];
    }
    printf("%d", count);
    return 0;
}
