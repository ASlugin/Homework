#include "InfixToPostfix.h"
#include "../Stack/Stack.h"
#include <stdbool.h>
#include <string.h>

bool isDigit(const char element)
{
    return element >= '0' && element <= '9';
}

bool isOperation(const char element)
{
    return element == '+' || element == '-' || element == '*' || element == '/';
}

bool isAcceptableSymbol(const char element)
{
    return isDigit(element) || isOperation(element) || element == '(' || element == ')' || element == ' ';
}

bool isPriorityOfPrevHigher(const char prevElement)
{
    return prevElement == '*' || prevElement == '/';
}

int fromInfixToPostfix(const char string[], char output[])
{
    const int lenght = strlen(string);
    int index = 0;
    StackElement* head = NULL;
    bool successPush = true;
    bool successPop = true;

    for (int i = 0; i < lenght; ++i)
    {
        if (!isAcceptableSymbol(string[i]))
        {
            deleteStack(&head);
            return -1;
        }
        if (isDigit(string[i]))
        {
            output[index] = string[i];
            ++index;
            output[index] = ' ';
            ++index;
        }
        if (string[i] == '(')
        {
            push(&head, string[i], &successPush);
            if (!successPush)
            {
                deleteStack(&head);
                return -2;
            }
        }
        if (string[i] == ')')
        {
            char prevElement = pop(&head, &successPop);
            if (!successPop)
            {
                deleteStack(&head);
                return -2;
            }
            while (prevElement != '(')
            {
                output[index] = prevElement;
                ++index;
                output[index] = ' ';
                ++index;
                prevElement = pop(&head, &successPop);
                if (!successPop)
                {
                    deleteStack(&head);
                    return -2;
                }
            }
        }
        if (isOperation(string[i]))
        {
            if (isEmpty(head))
            {
                push(&head, string[i], &successPush);
                if (!successPush)
                {
                    deleteStack(&head);
                    return -2;
                }
            }
            else
            {
                char prevElement = pop(&head, &successPop);
                if (!successPop)
                {
                    deleteStack(&head);
                    return -2;
                }
                if (prevElement == '(' || !isPriorityOfPrevHigher(prevElement))
                {
                    push(&head, prevElement, &successPush);
                    if (!successPush)
                    {
                        deleteStack(&head);
                        return -2;
                    }
                    push(&head, string[i], &successPush);
                    if (!successPush)
                    {
                        deleteStack(&head);
                        return -2;
                    }
                }
                else
                {
                    output[index] = prevElement;
                    ++index;
                    output[index] = ' ';
                    ++index;
                    push(&head, string[i], &successPush);
                    if (!successPush)
                    {
                        deleteStack(&head);
                        return -2;
                    }
                }
            }
        }
    }

    while (!isEmpty(head))
    {
        char element = pop(&head, &successPop);
        if (!successPop)
        {
            deleteStack(&head);
            return -2;
        }
        output[index] = element;
        ++index;
        output[index] = ' ';
        ++index;
    }
    output[index - 1] = '\0';
    deleteStack(&head);
    return 0;
}