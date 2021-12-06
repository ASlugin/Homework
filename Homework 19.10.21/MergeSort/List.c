#include "List.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SIZE 30

typedef struct ListElement
{
    char name[SIZE];
    char number[SIZE];
    struct ListElement* next;
} ListElement;

typedef struct List
{
    int length;
    struct ListElement* head;
    struct ListElement* tail;
} List;

List* createList(void)
{
    return calloc(1, sizeof(List));
}

void deleteList(List** list)
{
    while ((*list)->head != NULL)
    {
        ListElement* elementForDelete = (*list)->head;
        (*list)->head = (*list)->head->next;
        free(elementForDelete);
    }
    free(*list);
    *list = NULL;
}

bool isEmpty(List* list)
{
    if (list == NULL)
    {
        return true;
    }
    return list->head == NULL;
}

bool add(List* list, const char name[], const char number[])
{
    ListElement* newElement = calloc(1, sizeof(ListElement));
    if (newElement == NULL)
    {
        return false;
    }
    strcpy(newElement->name, name);
    strcpy(newElement->number, number);

    if (list->head == NULL)
    {
        list->head = newElement;
        list->tail = newElement;
        list->length++;
        return true;
    }
    list->tail->next = newElement;
    list->tail = newElement;
    list->length++;
    return true;
}

int getLength(List* list)
{
    if (list == NULL)
    {
        return -1;
    }
    return list->length;
}

char* getName(List* list)
{
    if (list == NULL || list->head == NULL)
    {
        return NULL;
    }
    return list->head->name;
}

char* getNumber(List* list)
{
    if (list == NULL || list->head == NULL)
    {
        return NULL;
    }
    return list->head->number;
}

bool pop(List* list, char* name, char* number)
{
    if (list == NULL || list->head == NULL)
    {
        return false;
    }
    strcpy(name, getName(list));
    strcpy(number, getNumber(list));
    if (list->tail == list->head)
    {
        free(list->head);
        list->head = NULL;
        list->tail = NULL;
        list->length--;
        return true;
    }
    ListElement* elementForDelete = list->head;
    list->head = list->head->next;
    free(elementForDelete);
    list->length--;
    return true;
}

void printListRecursive(ListElement* element)
{
    printf("%s - %s\n", element->name, element->number);
    if (element->next != NULL)
    {
        printListRecursive(element->next);
    }
}

void printList(List* list)
{
    if (!isEmpty(list))
    {
        printListRecursive(list->head);
    }
}

List* readDataFromFile(const char nameFile[])
{
    FILE* file = fopen(nameFile, "r");
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
        char name[SIZE] = {'\0'};
        char number[SIZE] = {'\0'};
        fscanf(file, "%s", name);
        fscanf(file, "%*c%*c%*c%s", number);
        if (!add(list, name, number))
        {
            fclose(file);
            deleteList(&list);
            return NULL;
        }
    }
    fclose(file);
    return list;
}