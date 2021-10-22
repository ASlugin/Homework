#include <stdio.h>
#include "Stack.h"
#include "Tests.h"

int main()
{
    if (!tests())
    {
        printf("%s", "Tests is failed!");
        return 0;
    }

    StackElement* head = NULL;
    if (isEmpty(head))
    {
        printf("%s\n", "Stack is empty");
    }

    head = push(head, 10);
    if (head == NULL)
    {
        printf("%s\n", "Allocation error");
        return 0;
    }
    head = push(head, 15);
    if (head == NULL)
    {
        printf("%s\n", "Allocation error");
        return 0;
    }
    head = push(head, 30);
    if (head == NULL)
    {
        printf("%s\n", "Allocation error");
        return 0;
    }

    if (!isEmpty(head))
    {
        printf("%d\n", pop(&head));
    }
    if (!isEmpty(head))
    {
        printf("%d\n", pop(&head));
    }

    deleteStack(&head);
    if (isEmpty(head))
    {
        printf("%s\n", "Stack is empty");
    }
    return 0;
}