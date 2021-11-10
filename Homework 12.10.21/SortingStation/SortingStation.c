#include <stdio.h>
#include "InfixToPostfix.h"
#include "Tests.h"

int main()
{
    if (!areTestsPassing())
    {
        printf("%s", "Tests failed!");
        return -1;
    }

    #define SIZE 300
    printf("Enter expression in infix notation of less than %d characters: ", SIZE);
    char string[SIZE] ="\0";
    gets_s(string, SIZE);

    char result[SIZE] = "\0";
    switch (fromInfixToPostfix(string, result, SIZE))
    {
        case 0:
        {
            printf("Result: %s", result);
            return 0;
        }
        case -1:
        {
            printf("%s", "There was an invalid character.");
            return -1;
        }
        case -2:
        {
            printf("%s", "Stack error");
            return -1;
        }
        case -3:
        {
            printf("%s", "Maximum length of result string is exceeded.");
            return -1;
        }
        default:
        {
            return -1;
        }
    }
}