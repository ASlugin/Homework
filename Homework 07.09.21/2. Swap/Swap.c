#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(int argc, char* argv[])
{
    if (argc > 1)
    {
        return 1; //without tests
    }
    int a = 0;
    int b = 0;
    printf("%s", "Enter value \"a\" and \"b\": ");
    scanf("%d %d", &a, &b);
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    printf("%s %d %d","Swap \"a\" and \"b\":", a, b);
    return 0;
}