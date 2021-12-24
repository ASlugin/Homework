#include "Test.h"
#include "Lexer.h"

#define SIZE 100
#define AMOUNT 15

bool testPassed(void)
{
    const char arrayString[AMOUNT][SIZE] =
    {
        "1",
        "123",
        "12.3",
        "12.312e456",
        "987.31E+4",
        "54.12E-987",
        "2.",
        "2.1E",
        "2E",
        "7+789",
        "31.123.12",
        "12.132E+"
        "95.45e-97e+31",
        ".456",
        "e+987"
    };
    const bool result[AMOUNT] = {true, true, true, true, true, true, false, false , false, false , false , false , false , false , false};
    
    for (int i = 0; i < AMOUNT; ++i)
    {
        if (isItRealNumber(arrayString[i]) != result[i])
        {
            return false;
        }
    }
    return true;
}
