#define _CRT_SECURE_NO_WARNINGS
#include "List.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SIZE 500

typedef struct ListElement
{
    char string[SIZE];
    struct ListElement* previous;
    struct ListElement* next;
} ListElement;

typedef struct List
{
    ListElement* head;
    ListElement* tail;
} List;

List* createList()
{
    return calloc(1, sizeof(List));
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

bool addWithoutRepeating(List* list, const char newString[])
{
    if (list == NULL)
    {
        return false;
    }
    
    if (list->head == NULL)
    {
        ListElement* newElement = calloc(1, sizeof(ListElement));
        if (newElement == NULL)
        {
            return false;
        }
        strcpy(newElement->string, newString);
        list->head = newElement;
        list->tail = newElement;
        return true;
    }

    bool thereIsStringInList = false;
    ListElement* currentElement = list->head;
    while (currentElement != NULL && !thereIsStringInList)
    {
        if (strcmp(currentElement->string, newString) == 0)
        {
            thereIsStringInList = true;
        }
        currentElement = currentElement->next;
    }
    
    if (!thereIsStringInList)
    {
        ListElement* newElement = calloc(1, sizeof(ListElement));
        if (newElement == NULL)
        {
            return false;
        }
        strcpy(newElement->string, newString);
        list->tail->next = newElement;
        list->tail = newElement;
        return true;
    }

    return true;
}

bool add(List* list, const char newString[])
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
    strcpy(newElement->string, newString);

    if (list->head == NULL)
    {
        list->head = newElement;
        list->tail = newElement;
        return true;
    }
    
    newElement->previous = list->tail;
    list->tail->next = newElement;
    list->tail = newElement;
    return true;
}

List* CreateListAndReadDataFromFile(const char name[])
{
    FILE* file = fopen(name, "r");
    if (file == NULL)
    {
        return NULL;
    }
    List* list = createList();
    if (list == NULL)
    {
        fclose(file);
        return NULL;
    }

    while (!feof(file))
    {
        char string[SIZE] = {'\0'};
        fgets(string, SIZE, file);
        if (strcmp(string, "") != 0 && !add(list, string))
        {
            fclose(file);
            deleteList(&list);
            return NULL;
        }
    }
    fclose(file);
    return list;
}

List* deleteRepeatingString(List* list)
{
    if (list == NULL)
    {
        return list;
    }
    List* newList = createList();
    if (newList == NULL)
    {
        return list;
    }

    ListElement* currentElement = list->head;
    while (currentElement != NULL)
    {
        char string[SIZE] = {'\0'};
        strcpy(string, currentElement->string);
        if (!addWithoutRepeating(newList, string))
        {
            deleteList(&newList);
            return NULL;
        }
        currentElement = currentElement->next;
    }
    deleteList(&list);
    return newList;
}

void printList(List* list)
{
    if (isEmpty(list))
    {
        return;
    }
    ListElement* currentElement = list->head;
    while (currentElement != NULL)
    {
        printf("%s", currentElement->string);
        currentElement = currentElement->next;
    }
}