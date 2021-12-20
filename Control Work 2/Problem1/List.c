#define _CRT_SECURE_NO_WARNINGS
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
    ListElement* tail;
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

bool add(List* list, Position* position, int value)
{
    if (list == NULL)
    {
        return false;
    }

    ListElement* newElement = calloc(1, sizeof(ListElement));
    if (newElement == NULL)
    {
        return false;
    }
    newElement->value = value;
    
    if (position->position == NULL)
    {
        newElement->next = list->head;
        list->head = newElement;
        if (list->tail == NULL)
        {
            list->tail = newElement;
        }
        return true;
    }

    if (list->head == NULL)
    {
        list->head = newElement;
        list->tail = newElement;
        return true;
    }

    newElement->next = position->position->next;
    position->position->next = newElement;
    if (position->position == list->tail)
    {
        list->tail = newElement;
    }
    return true;
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

Position* last(List* list, Position* index)
{
    if (list == NULL || index == NULL)
    {
        return NULL;
    }
    index->position = list->tail;
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

List* createListAndReadDataFromFile(const char name[])
{
    FILE* file = fopen(name, "r");
    if (file == NULL)
    {
        return NULL;
    }

    List* list = calloc(1, sizeof(List));
    if (list == NULL)
    {
        fclose(file);
        return NULL;
    }

    Position* index = createPosition();
    if (index == NULL)
    {
        fclose(file);
        free(list);
        return NULL;
    }

    while (!feof(file))
    {
        int value = 0;
        fscanf(file, "%d", &value);
        index = last(list, index);
        if (!add(list, index, value))
        {
            fclose(file);
            deleteList(&list);
            return NULL;
        }
    }
    fclose(file);
    deletePosition(&index);
    return list;
}

bool deleteValue(List* list, Position* indexForDelete)
{
    if (isEmpty(list) || !isEmpty(list) && (indexForDelete == NULL || indexForDelete->position == NULL))
    {
        return true;
    }
    if (indexForDelete->position == list->head)
    {
        list->head = list->head->next;
        if (list->tail == indexForDelete->position)
        {
            list->tail = NULL;
        }
        free(indexForDelete->position);
        indexForDelete->position = NULL;
        return true;
    }

    ListElement* prevElement = list->head;
    while (prevElement->next != indexForDelete->position)
    {
        prevElement = prevElement->next;
    }
    
    
    prevElement->next = indexForDelete->position->next;
    if (list->tail == indexForDelete->position)
    {
        list->tail = prevElement;
    }
    free(indexForDelete->position);
    indexForDelete->position = NULL;
    return true;
}

int get(Position* index)
{
    if (index == NULL || index->position == NULL)
    {
        return 0;
    }
    return index->position->value;
}

bool swapList(List* list)
{
    if (isEmpty(list))
    {
        return true;
    }
    
    Position* index = createPosition();
    if (index == NULL)
    {
        return false;
    }
    index->position = NULL;
    
    Position* indexLast = createPosition();
    if (indexLast == NULL)
    {
        deletePosition(&index);
        return false;
    }
    bool flag = true;
    while (index->position == NULL || index->position->next != list->tail)
    {
        indexLast = last(list, indexLast);
        int valueLast = get(indexLast);
        if (!deleteValue(list, indexLast) || !add(list, index, valueLast))
        {
            deletePosition(&index);
            deletePosition(&indexLast);
            return false;
        }
        
        if (flag)
        {
            index = first(list, index);
            flag = false;
        }
        else
        {
            index = next(index);
        }
    }

    deletePosition(&index);
    deletePosition(&indexLast);
    return true;
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