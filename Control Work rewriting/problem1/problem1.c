#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool palindrom(char string[])
{
    int length = strlen(string);
    int position = 0;
    for (int i = 0; i < length; ++i)
    {
        if (string[i] != ' ')
        {
            if (string[i] >= 'A' && string[i] <= 'Z') {
                string[position] = string[i] + 'a' - 'A';
            }
            else
            {
                string[position] = string[i];
            }
            position++;
        }
    }

    for (int i = 0; i < length / 2 - 1; ++i)
    {
        if (string[i] != string[length - i - 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    char string[300] = "";
    gets(string);
    
    if (palindrom(string))
    {
        printf("%s", "String is palindrom");
    }
    else
    {
        printf("%s", "String is not palindrom");
    }
    return 0;
}
