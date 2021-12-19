#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    if (argc > 1)
    {
        return 1; //without tests
    }
    char string[51] = { 0 };
    printf("%s", "Enter string no longer than 50 characters: ");
    scanf("%s", string);
    int sumOpen = 0;
    const unsigned length = strlen(string);
    for (unsigned i = 0; i < length; ++i)
    {
        if (string[i] == '(')
        {
            sumOpen++;
        }
        if (string[i] == ')')
        {
            sumOpen--;
            if (sumOpen < 0)
            {
                break;
            }
        }
    }
    if (sumOpen == 0)
    {
        printf("%s", "Correct");
    }
    else
    {
        printf("%s", "Not correct");
    }
    return 0;
}
