#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "../Stack/Stack.h"

bool isAcceptableSymbol(const char element)
{
    return element >= '0' && element <= '9' || element == '+' || element == '-' || element == '*' || element == '/' || element == ' ';
}

// If successful, returns result of the calculation,
// else "success" is false and return error code:
// -1 - stack error
// -2 - entered not digit and not operation
// -3 - more digits than operations
int calculate(const char string[], bool* success)
{
    StackElement* head = NULL;
    const int length = strlen(string);
    bool successPush = true;
    bool successPop = true;
    for (int i = 0; i < length; ++i)
    {
        if (!isAcceptableSymbol(string[i]))
        {
            *success = false;
            deleteStack(&head);
            return -2;
        }
        if (string[i] >= '0' && string[i] <= '9')
        {
            int number = string[i] - '0';
            push(&head, number, &successPush);
            if (!successPush)
            {
                *success = false;
                deleteStack(&head);
                return -1;
            }
        }
        else if (string[i] != ' ' && head != NULL && head->next != NULL)
        {
            int secondNumber = pop(&head, &successPop);
            if (!successPop)
            {
                *success = false;
                deleteStack(&head);
                return -1;
            }
            int firstNumber = pop(&head, &successPop);
            if (!successPop)
            {
                *success = false;
                deleteStack(&head);
                return -1;
            }
            int number = 0;
            switch (string[i])
            {
                case '-':
                {
                    number = firstNumber - secondNumber;
                    break;
                }
                case '+':
                {
                    number = firstNumber + secondNumber;
                    break;
                }
                case '*':
                {
                    number = firstNumber * secondNumber;
                    break;
                }
                case '/':
                {
                    number = firstNumber / secondNumber;
                    break;
                }
            }
            push(&head, number, &successPush);
            if (!successPush)
            {
                *success = false;
                deleteStack(&head);
                return -1;
            }
        }
    }
    int result = pop(&head, &successPop);
    if (!successPop)
    {
        *success = false;
        deleteStack(&head);
        return -1;
    }

    if (!isEmpty(head))
    {
        *success = false;
        deleteStack(&head);
        return -3;
    }
    
    *success = true;
    return result;
}

bool areTestsPassing()
{
    #define AMOUNT 3
    const char string[AMOUNT][20] = {"9 3 / 1 + 5 2 * +", "9 6 - 1 2 + *", "8 6 9 - +"};
    const int result[AMOUNT] = {14, 9, 5};
    for (int i = 0; i < AMOUNT; ++i)
    {
        bool successCalculate = true;
        if (calculate(string[i], &successCalculate) != result[i] || !successCalculate)
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
            printf("%s", "Tests failed!");
        }
        return -1;
    }
    if (argc > 1)
    {
        return 0;
    }

    #define SIZE 300
    printf("%s%d%s", "Enter expression in postfix form less then ", SIZE, " characters: ");
    char string[SIZE] = "\0";
    gets_s(string, SIZE);
    
    bool successCalculate = true;
    int result = calculate(string, &successCalculate);
    if (successCalculate)
    {
        printf("%s%d", "Result: ", result);
        return 0;
    }

    switch (result)
    {
        case -1:
        {
            printf("%s", "Stack error");
            break;
        }
        case -2:
        {
            printf("%s", "Error. There was symbol that is not number and is not operation.");
            break;
        }
        case -3:
        {
            printf("%s", "Error. There were more digits than operations.");
            break;
        }
    }
    return -1;
}