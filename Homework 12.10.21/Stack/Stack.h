#pragma once

#include <stdbool.h>

// Structure for stack elements
typedef struct StackElement
{
    int value;
    struct StackElement* next;
} StackElement;

// Adds new element to stack. If successful, then "success" is true, else false
void push(StackElement** head, int number, bool* success);

// Returns value of top element of stack. If successful, then "success" is true, else false and return 0
int pop(StackElement** head, bool* success);

// Returns true if stack is empty
bool isEmpty(StackElement* head);

// Removes all elements of stack
void deleteStack(StackElement** head);
