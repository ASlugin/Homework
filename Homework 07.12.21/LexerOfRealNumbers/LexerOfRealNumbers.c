#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Lexer.h"
#include "Test.h"

#define SIZE 500

int main(int argc, char* argv[])
{
    if (!testPassed())
    {
        if (argc <= 1)
        {
            printf("Test failed!\n");
        }
        return -1;
    }
    if (argc > 1)
    {
        return 0;
    }

    char string[SIZE] = {'\0'};
    printf("Enter string: ");
    gets_s(string, SIZE);

    if (isItRealNumber(string))
    {
        printf("It is real number\n");
    }
    else
    {
        printf("It is not real number\n");
    }
    return 0;
}
