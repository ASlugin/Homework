#include <stdio.h>

int main()
{
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