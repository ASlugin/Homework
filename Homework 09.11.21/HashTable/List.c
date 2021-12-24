#define _CRT_SECURE_NO_WARNINGS
#include "List.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListElement
{
    char word[SIZE_WORD];
    int counter;
    struct ListElement* next;
} ListElement;

typedef struct List
{
    int listLength;
    ListElement* head;
} List;

List* createList()
{
    return calloc(1, sizeof(List));
}

void deleteList(List** list)
{
    if (*list == NULL)
    {
        return;
    }
    ListElement* currentElement = (*list)->head;
    while (currentElement != NULL)
    {
        (*list)->head = (*list)->head->next;
        free(currentElement);
        currentElement = (*list)->head;
    }
    free(*list);
    *list = NULL;
}

bool isEmpty(List* list)
{
    return list == NULL || list->head == NULL;
}

bool addToList(List** list, const char newWord[], const int currentCounter)
{
    if (*list == NULL)
    {
        *list = createList();
        if (*list == NULL)
        {
            return false;
        }
        (*list)->listLength = 0;
    }
    
    ListElement* currentElement = (*list)->head;
    while (currentElement != NULL && strcmp(currentElement->word, newWord) != 0)
    {
        currentElement = currentElement->next;
    }
    
    if (currentElement == NULL)
    {
        ListElement* newElement = calloc(1, sizeof(ListElement));
        if (newElement == NULL)
        {
            return false;
        }
        newElement->counter = currentCounter;
        strcpy(newElement->word, newWord);

        ++(*list)->listLength;
        if ((*list)->head != NULL)
        {
            newElement->next = (*list)->head;
        }
        (*list)->head = newElement;
        return true;
    }
    
    currentElement->counter += currentCounter;
    return true;
}

char* getWordFromHead(List* list)
{
    if (list == NULL || list->head == NULL)
    {
        return NULL;
    }
    return list->head->word;
}

int getValueOfCounterFromHead(List* list)
{
    if (list == NULL || list->head == NULL)
    {
        return 0;
    }
    return list->head->counter;
}

void deleteElementFromHead(List* list)
{
    if (list == NULL || list->head == NULL)
    {
        return;
    }
    ListElement* elementForDelete = list->head;
    list->head = list->head->next;
    free(elementForDelete);
}

void printList(List* list)
{
    if (list == NULL)
    {
        return;
    }
    ListElement* current = list->head;
    while (current != NULL)
    {
        printf("%s %d\n", current->word, current->counter);
        current = current->next;
    }
}

int getListLength(List* list)
{
    if (list == NULL)
    {
        return 0;
    }
    return list->listLength;
}

int getCounter(List* list, const char word[])
{
    if (list == NULL)
    {
        return 0;
    }
    ListElement* current = list->head;
    while (current != NULL && strcmp(current->word, word) != 0)
    {
        current = current->next;
    }
    return current == NULL ? 0 : current->counter;
}