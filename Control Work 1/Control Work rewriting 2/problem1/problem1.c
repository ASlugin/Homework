#define _CTR_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

// 0 - numbers are equal
// 1 - first number is greater than second number
// 2 - second number is greater than first number
int whichNumberIsGreater(const bool first[], const bool second[], const int amount)
{
    for (int i = 0; i < amount; ++i)
    {
        if (first[i] && !second[i])
        {
            return 1;
        }
        else if (!first[i] && second[i])
        {
            return 2;
        }
    }
    return 0;
}

bool areTestsPassing()
{
    #define AMOUNTTESTS 3
    #define SIZETEST 8
    bool firstNumber[AMOUNTTESTS][SIZETEST] =
    {
        {false, true, false, true, true, false, false, true}, //89
        {false, false, false, false, false, true, false, true}, //5
        {false, true, false, false, true, true, false, true} //77
    };
    bool secondNumber[AMOUNTTESTS][SIZETEST] =
    {
        {false, false, true, false, true, true, false, true}, //45
        {false, false, false, false, false, true, false, true}, //5
        {true, false, true, true, false, false, false, true} //177
    };
    const int result[AMOUNTTESTS] = {1, 0, 2};
    
    for (int i = 0; i < AMOUNTTESTS; ++i)
    {
        if (whichNumberIsGreater(firstNumber[i], secondNumber[i], SIZETEST) != result[i])
        {
            return false;
        }
    }
    return true;
}

int main(int argc, char* argv[])
{
    if (!areTestsPassing())
    {
        if (argc <= 1)
        {
            printf("Tests failed!");
        }
        return -1;
    }
    if (argc > 1)
    {
        return 0;
    }

    #define SIZE 8
    bool firstNumber[SIZE] = {true, false, false, true, true, false, true, false}; //154
    bool secondNumber[SIZE] = {false, true, false, true, true, false, false, true}; //89
    
    switch (whichNumberIsGreater(firstNumber, secondNumber, SIZE))
    {
        case 0:
        {
            printf("Numbers are equal\n");
            return 0;
        }
        case 1:
        {
            printf("First number is greater than second number\n");
            return 0;
        }
        case 2:
        {
            printf("Second number is greater than first number\n");
            return 0;
        }
        default:
        {
            return -1;
        }
    }
}
