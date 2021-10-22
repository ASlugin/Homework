#pragma once

#include <stdlib.h>
#include <stdbool.h>

// Structure for stack elements
typedef struct StackElement
{
    int value;
    struct StackElement* next;
} StackElement;

// Returns pointer to new element in stack, if allocation is not successful it returns NULL
StackElement* push(StackElement* head, int number);

// Returns value of top element of stack
int pop(StackElement** head);

// Returns true if stack is empty
bool isEmpty(StackElement* head);

// Removes all elements of stack
void deleteStack(StackElement** head);
