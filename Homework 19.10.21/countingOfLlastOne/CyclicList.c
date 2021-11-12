#include "CyclicList.h"
#include <stdlib.h>

typedef struct ListElement
{
    int value;
    struct ListElement* next;
} ListElement;

typedef struct List
{
    ListElement* head;
    ListElement* last;
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

bool isEmpty(List* list)
{
    return list->head == NULL;
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

Position* last(List* list, Position* index)
{
    if (list == NULL || index == NULL)
    {
        return NULL;
    }
    if (isEmpty(list))
    {
        index->position = NULL;
        return index;
    }
    index->position = list->last;
    return index;
}

void copyPosition(Position* from, Position* toThere)
{
    if (from == NULL || toThere == NULL)
    {
        return;
    }
    toThere->position = from->position;
}

bool isOneElementLeft(List* list)
{
    if (list == NULL || isEmpty(list))
    {
        return false;
    }
    return list->head == list->head->next;
}

bool add(List* list, Position* afterWhichAdd, int value)
{
    if (list == NULL || (list->head != NULL && (afterWhichAdd == NULL || afterWhichAdd->position == NULL)))
    {
        return false;
    }
    ListElement* newElement = calloc(1, sizeof(ListElement));
    if (newElement == NULL)
    {
        return false;
    }
    newElement->value = value;
    
    if (isEmpty(list))
    {
        list->head = newElement;
        list->last = newElement;
        newElement->next = newElement;
        return true;
    }
    newElement->next = afterWhichAdd->position->next;
    if (afterWhichAdd->position == list->last)
    {
        list->last = newElement;
    }
    afterWhichAdd->position->next = newElement;
    return true;
}

bool deleteElement(List* list, Position* index)
{
    if (list == NULL || isEmpty(list) || index == NULL || index->position == NULL)
    {
        return false;
    }
    if (index->position == index->position->next)
    {
        free(index->position);
        list->head = NULL;
        list->last = NULL;
        index->position = NULL;
        return true;
    }

    ListElement* prevElement = list->head;
    while (prevElement->next != index->position)
    {
        prevElement = prevElement->next;
    }
    prevElement->next = index->position->next;

    if (index->position == list->head)
    {
        list->head = index->position->next;
    }
    if (index->position == list->last)
    {
        list->last = prevElement;
    }
    free(index->position);
    index->position = prevElement->next;
    return true;
}

void deleteList(List** list)
{
    if (!isEmpty(*list))
    {
        ListElement* elementForDelete = (*list)->head;
        while (elementForDelete != (*list)->last)
        {
            ListElement* nextForDelete = elementForDelete->next;
            free(elementForDelete);
            elementForDelete = nextForDelete;
        }
        free(elementForDelete);
    }
    free(*list);
    *list = NULL;
}

int get(Position* index)
{
    if (index == NULL || index->position == NULL)
    {
        return 0;
    }
    return index->position->value;
}