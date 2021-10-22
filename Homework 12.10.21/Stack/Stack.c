#include "Stack.h"

StackElement* push(StackElement* head, int number)
{
    StackElement* newStackElement = calloc(1, sizeof(StackElement));
    if (newStackElement == NULL)
    {
        return NULL;
    }
    newStackElement->value = number;
    newStackElement->next = head;
    return newStackElement;
}

int pop(StackElement** head)
{
    int value = (*head)->value;
    StackElement* temp = *head;
    *head = (*head)->next;
    free(temp);
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
        pop(head);
    }
}