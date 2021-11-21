#include "MergeSort.h"
#include <string.h>

#define SIZE 30

// Moves one element of list from list "from" to list "toHere"
// If not successful, returns false
bool moveOneElement(List* from, List* toHere)
{
    if (from == NULL || toHere == NULL || isEmpty(from))
    {
        return false;
    }

    char name[SIZE] = {'\0'};
    char number[SIZE] = {'\0'};
    if (!pop(from, name, number))
    {
        return false;
    }
    return add(toHere, name, number);
}

// Moves specified amount of elements from list "from" to list "toHere"
// If not successful, returns false
bool moveElements(List* from, List* toHere, const int amount)
{
    if (from == NULL || toHere == NULL || amount < 0 || getLength(from) < amount)
    {
        return false;
    }
    for (int i = 0; i < amount; ++i)
    {
        if (!moveOneElement(from, toHere))
        {
            return false;
        }
    }
    return true;
}

List* listForMoveElement(List* left, List* right, SortBy key)
{
    if (isEmpty(left))
    {
        if (isEmpty(right))
        {
            return NULL;
        }
        else
        {
            return right;
        }
    }
    else if (isEmpty(right))
    {
        return left;
    }
    else
    {
        if (key == name && strcmp(getName(left), getName(right)) <= 0 || key == number && strcmp(getNumber(left), getNumber(right)) <= 0)
        {
            return left;
        }
        else
        {
            return right;
        }
    }
}

bool mergeLists(List* list, List* left, List* right, SortBy key)
{
    List* listForMove = listForMoveElement(left, right, key);
    while (listForMove != NULL)
    {
        if (!moveOneElement(listForMove, list))
        {
            return false;
        }
        listForMove = listForMoveElement(left, right, key);
    }
    return true;
}

bool mergeSort(List* list, SortBy key)
{
    if (key != name && key != number)
    {
        return false;
    }
    const int length = getLength(list);
    if (length <= 0)
    {
        return false;
    }
    if (length == 1)
    {
        return true;
    }

    List* left = createList();
    if (left == NULL)
    {
        return false;
    }
    List* right = createList();
    if (right == NULL)
    {
        deleteList(&left);
        return false;
    }
    
    if (!moveElements(list, left, length / 2) || !moveElements(list, right, (length + 1) / 2))
    {
        deleteList(&left);
        deleteList(&right);
        return false;
    }
    
    if (!mergeSort(left, key) || !mergeSort(right, key))
    {
        deleteList(&left);
        deleteList(&right);
        return false;
    }

    if (!mergeLists(list, left, right, key))
    {
        deleteList(&left);
        deleteList(&right);
        return false;
    }

    deleteList(&left);
    deleteList(&right);
    return true;
}