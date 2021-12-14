#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#define SIZE 20

bool isCorrectSymbol(const char symbol, int* state)
{
    switch (*state)
    {
        case 0:
        case 1:
        case 4:
        case 5:
        {
            if (symbol <= '9' && symbol >= '0')
            {
                ++(*state);
                return true;
            }
            return false;
        }
        case 2:
        {
            if (symbol == '.')
            {
                ++(*state);
                return true;
            }
            return false;
        }
        case 3:
        {
            if (symbol == 'B' || symbol == 'S' || symbol == 'M')
            {
                ++(*state);
                return true;
            }
            return false;
        }
        case 6:
        {
            if (symbol == '-')
            {
                ++(*state);
                return true;
            }
            return false;
        }
        case 7:
        case 8:
        {
            if (symbol == 'm')
            {
                ++(*state);
                return true;
            }
            return false;
        }
        default:
        {
            return false;
        }
    }
}

bool isCorrectString(char* string)
{
    const int length = strlen(string);
    int state = 0;
    for (int i = 0; i < length; ++i)
    {
        if (!isCorrectSymbol(string[i], &state))
        {
            return false;
        }
    }
    return true;
}

bool isTestsPassing(void)
{
    #define AMOUNTTEST 5
    const char string[AMOUNTTEST][SIZE] = {"21.B10-mm", "19.M03-mm", "134.B10-mm", "17.G04-mm", "16M07-pm"};
    bool result[AMOUNTTEST] = {true, true, false, false, false};
    for (int i = 0; i < AMOUNTTEST; ++i)
    {
        if (isCorrectString(string[i]) != result[i])
        {
            return false;
        }
    }
    return true;
}

int main(void)
{
    if (!isTestsPassing())
    {
        printf("Tests failed!\n");
        return -1;
    }

    char string[SIZE] = {'\0'};
    printf("Enter number of group: ");
    scanf("%s", string);
    
    if (isCorrectString(string))
    {
        printf("Number of group is correct\n");
    }
    else
    {
        printf("Number of group is not correcrt\n");
    }

    return 0;
}