#pragma once

#include <stdbool.h>

// Structure for stack elements
typedef struct StackElement
{
    int value;
    struct StackElement* next;
} StackElement;

// Adds new element to stack
void push(StackElement** head, int number);

// Returns value of top element of stack, if stack is empty returns 0 and writes false to "success"
int pop(StackElement** head, bool* success);

// Returns true if stack is empty
bool isEmpty(StackElement* head);

// Removes all elements of stack
void deleteStack(StackElement** head);
