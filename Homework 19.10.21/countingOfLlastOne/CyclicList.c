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
    index->position = list->head;
    while (index->position->next != list->head)
    {
        index->position = index->position->next;
    }
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
        newElement->next = newElement;
        return true;
    }
    newElement->next = afterWhichAdd->position->next;
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
        index->position = NULL;
        return true;
    }

    Position* prevElement = createPosition();
    if (prevElement == NULL)
    {
        return false;
    }
    prevElement->position = list->head;
    while (prevElement->position->next != index->position)
    {
        prevElement = next(prevElement);
    }
    prevElement->position->next = index->position->next;
    if (index->position == list->head)
    {
        list->head = index->position->next;
    }
    free(index->position);
    index->position = NULL;
    free(prevElement);
    return true;
}

void deleteList(List** list)
{
    if (!isEmpty(*list))
    {
        Position* elementForDelete = createPosition();
        if (elementForDelete == NULL)
        {
            return;
        }
        while (!isOneElementLeft(*list))
        {
            elementForDelete->position = (*list)->head;
            deleteElement(*list, elementForDelete);
        }
        elementForDelete->position = (*list)->head;
        free(elementForDelete->position);
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