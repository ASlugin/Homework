#include "Tests.h"
#include "Stack.h"

bool testsPushAndPop()
{
    StackElement* head = NULL;
    #define SIZE 3
    int arrayElements[SIZE] = {3, 14, -9};
    for (int i = 0; i < SIZE; ++i)
    {
        head = push(head, arrayElements[i]);
        if (head == NULL)
        {
            deleteStack(&head);
            return false;
        }
    }
    
    for (int i = SIZE - 1; i >= 0; --i)
    {
        if (isEmpty(head))
        {
            return false;
        }
        if (pop(&head) != arrayElements[i])
        {
            deleteStack(&head);
            return false;
        }
    }
    deleteStack(&head);
    return true;
}

bool testIsEmpty()
{
    StackElement* head = NULL;
    if (!isEmpty(head))
    {
        return false;
    }
    head = push(head, 9);
    if (isEmpty(head))
    {
        return false;
    }
    deleteStack(&head);
    return true;
}

bool testDeletedStack()
{
    StackElement* head = NULL;
    int arrayElements[SIZE] = {3, 14, -9};
    for (int i = 0; i < SIZE; ++i)
    {
        head = push(head, arrayElements[i]);
        if (head == NULL)
        {
            deleteStack(&head);
            return false;
        }
    }
    deleteStack(&head);
    if (head != NULL)
    {
        return false;
    }
    return true;
}

bool tests()
{
    return testsPushAndPop() && testIsEmpty() && testDeletedStack();
}