#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
#include "Tests.h"

int main()
{
    if (!areTestsPassing())
    {
        printf("%s", "Tests failed!");
        return -1;
    }

    StackElement* head = NULL;
    if (isEmpty(head))
    {
        printf("%s\n", "Stack is empty");
    }

    bool successPush = true;
    push(&head, 10, &successPush);
    if (!successPush)
    {
        printf("%s", "Push: allocation error");
        return -1;
    }
    push(&head, 15, &successPush);
    if (!successPush)
    {
        printf("%s", "Push: allocation error");
        return -1;
    }
    push(&head, 30, &successPush);
    if (!successPush)
    {
        printf("%s", "Push: allocation error");
        return -1;
    }

    bool successPop = true;
    int value = pop(&head, &successPop);
    if (!successPop)
    {
        printf("%s\n", "Pop error. Stack is empty");
    }
    else
    {
        printf("%d\n", value);
    }
    value = pop(&head, &successPop);
    if (!successPop)
    {
        printf("%s\n", "Pop error. Stack is empty");
    }
    else
    {
        printf("%d\n", value);
    }
 
    deleteStack(&head);
    if (isEmpty(head))
    {
        printf("%s", "Stack is empty");
    }
    return 0;
}