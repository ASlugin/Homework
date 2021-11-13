#include "List.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct ListElement
{
    int value;
    struct ListElement* next;
} ListElement;

typedef struct List
{
    ListElement* head;
} List;

typedef struct Position
{
    ListElement* position;
} Position;

List* createList()
{
    return calloc(1, sizeof(List));
}

Position* createPosition()
{
    return calloc(1, sizeof(Position));
}

void deletePosition(Position** index)
{
    free(*index);
    *index = NULL;
}

void deleteList(List** list)
{
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

bool add(List* list, int value)
{
    ListElement* newElement = calloc(1, sizeof(ListElement));
    if (newElement == NULL)
    {
        return false;
    }
    newElement->value = value;

    if (list->head == NULL)
    {
        list->head = newElement;
        return true;
    }
    
    ListElement* currentElement = list->head;
    
    if (currentElement->value > value)
    {
        newElement->next = list->head;
        list->head = newElement;
        return true;
    }

    while (currentElement->next != NULL && currentElement->next->value < value)
    {
        currentElement = currentElement->next;
    }
    newElement->next = currentElement->next;
    currentElement->next = newElement;
    return true;
}

void deleteValue(List* list, int value)
{
    ListElement* currentElement = list->head;
    ListElement* prevElement = NULL;
    
    while (currentElement != NULL)
    {
        if (currentElement->value == value)
        {
            if (prevElement == NULL)
            {
                list->head = currentElement->next;
                free(currentElement);
                currentElement = list->head;
            }
            else
            {
                prevElement->next = currentElement->next;
                free(currentElement);
                currentElement = prevElement->next;
            }
        }
        else
        {
            prevElement = currentElement;
            currentElement = currentElement->next;
        }
    }
}

void printList(List* list)
{
    ListElement* currentElement = list->head;
    while (currentElement != NULL)
    {
        printf("%d ", currentElement->value);
        currentElement = currentElement->next;
    }
    printf("\n");
}

Position* first(List* list, Position* index)
{
    if (list == NULL || index == NULL)
    {
        return NULL;
    }
    index->position = list->head;
    return index;
}

Position* next(Position* index)
{
    if (index == NULL || index->position == NULL)
    {
        return NULL;
    }
    index->position = index->position->next;
    return index;
}

bool isThereNoElement(Position* index)
{
    if (index == NULL)
    {
        return true;
    }
    return index->position == NULL;
}

int get(Position* index)
{
    if (index == NULL || index->position == NULL)
    {
        return 0;
    }
    return index->position->value;
}