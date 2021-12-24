#include "Lexer.h"
#include <string.h>

enum State
{
    begin,
    digit,
    dot,
    digitAfterDot,
    exp,
    operation,
    digitAfterExp,
    fail
};

bool isDigit(const char symbol)
{
    return symbol >= '0' && symbol <= '9';
}

bool isCorrectSymbol(const char nextSymbol, enum State* state)
{
    switch (*state)
    {
        case begin:
        {
            if (isDigit(nextSymbol))
            {
                *state = digit;
                return true;
            }
            *state = fail;
            return false;
        }
        case digit:
        {
            if (isDigit(nextSymbol))
            {
                return true;
            }
            else if (nextSymbol == '.')
            {
                *state = dot;
                return true;
            }
            else if (nextSymbol == 'e' || nextSymbol == 'E')
            {
                *state = exp;
                return true;
            }
            *state = fail;
            return false;
        }
        case dot:
        {
            if (isDigit(nextSymbol))
            {
                *state = digitAfterDot;
                return true;
            }
            *state = fail;
            return false;
        }
        case digitAfterDot:
        {
            if (isDigit(nextSymbol))
            {
                *state = digitAfterDot;
                return true;
            }
            else if (nextSymbol == 'E' || nextSymbol == 'e')
            {
                *state = exp;
                return true;
            }
            *state = fail;
            return false;
        }
        case exp:
        {
            if (isDigit(nextSymbol))
            {
                *state = digitAfterExp;
                return true;
            }
            else if (nextSymbol == '+' || nextSymbol == '-')
            {
                *state = operation;
                return true;
            }
            *state = fail;
            return false;
        }
        case operation:
        {
            if (isDigit(nextSymbol))
            {
                *state = digitAfterExp;
                return true;
            }
            *state = fail;
            return false;
        }
        case digitAfterExp:
        {
            if (isDigit(nextSymbol))
            {
                *state = digitAfterExp;
                return true;
            }
            *state = fail;
            return false;
        }
        default:
        {
            *state = fail;
            return false;
        }
    }
}

bool isItRealNumber(const char string[])
{
    enum State state = begin;
    const int length = strlen(string);
    
    for (int i = 0; i < length; ++i)
    {
        if (!isCorrectSymbol(string[i], &state) || state == fail)
        {
            return false;
        }
    }
    return state == digit || state == digitAfterDot || state == digitAfterExp;
}