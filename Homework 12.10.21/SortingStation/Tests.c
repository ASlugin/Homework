#include "Tests.h"
#include "InfixToPostfix.h"
#include <string.h>

bool areTestsPassing()
{
    #define AMOUNT 4
    const char enteredString[AMOUNT][30] =
    {
        "(3+5)*9 - 8*2",
        "(1 + 1) * 2",
        "(5 + 6) * (4 - 7) / 3",
        "(1 + 2) * 3 / 9"
    };
    const char resultTest[AMOUNT][30] = 
    {
        "3 5 + 9 * 8 2 * -",
        "1 1 + 2 *",
        "5 6 + 4 7 - * 3 /",
        "1 2 + 3 * 9 /"
    };
    
    for (int i = 0; i < AMOUNT; ++i)
    {
        char output[30] = "\0";
        if (fromInfixToPostfix(enteredString[i], output) != 0)
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
