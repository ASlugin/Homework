#include "Stack.h"
#include <stdlib.h>

void push(StackElement** head, int number, bool* success)
{
    StackElement* newStackElement = calloc(1, sizeof(StackElement));
    if (newStackElement == NULL)
    {
        *success = false;
        return;
    }
    newStackElement->value = number;
    newStackElement->next = *head;
    *head = newStackElement;
    *success = true;
}

int pop(StackElement** head, bool* success)
{
    if (*head == NULL || head == NULL)
    {
        *success = false;
        return 0;
    }
    const int value = (*head)->value;
    StackElement* temp = *head;
    *head = (*head)->next;
    free(temp);
    *success = true;
    return value;
}

bool isEmpty(StackElement* head)
{
    return head == NULL;
}

void deleteStack(StackElement** head)
{
    while (!isEmpty(*head))
    {
        bool temp = true;
        int value = pop(head, &temp);
    }
}