#include "Tests.h"
#include "InfixToPostfix.h"
#include <string.h>

bool areTestsPassing()
{
    #define AMOUNT 5
    #define MAXLENGTH 30
    const char enteredString[AMOUNT][MAXLENGTH] =
    {
        "(3+5)*9 - 8*2",
        "(1 + 1) * 2",
        "(5 + 6) * (4 - 7) / 3",
        "(1 + 2) * 3 / 9",
        "1 - 2 + 3"
    };
    const char resultTest[AMOUNT][MAXLENGTH] =
    {
        "3 5 + 9 * 8 2 * -",
        "1 1 + 2 *",
        "5 6 + 4 7 - * 3 /",
        "1 2 + 3 * 9 /",
        "1 2 - 3 +"
    };
    
    for (int i = 0; i < AMOUNT; ++i)
    {
        char output[MAXLENGTH] = "\0";
        if (fromInfixToPostfix(enteredString[i], output, MAXLENGTH) != 0)
        {
            return false;
        }
        if (strcmp(output, resultTest[i]) != 0)
        {
            return false;
        }
    }
    return true;
}
