#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(int argc, char* argv[])
{
    if (argc > 1)
    {
        return 1; //without tests
    }
    int nameArray[10];
    printf("%s", "Enter 10 array elements: ");
    int count = 0;
    for (int i = 0; i < 10; ++i)
    {
        scanf("%d", &nameArray[i]);
        if (nameArray[i] == 0)
        {
            count++;
        }
    }
    printf("%s%d", "Zero elements: ", count);
    return 0;
}