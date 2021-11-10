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
    if (!add(toHere, name, number))
    {
        return false;
    }
    return true;
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

bool mergeLists(List* list, List* left, List* right, const int code)
{
    while (!isEmpty(left) || !isEmpty(right))
    {
        if (isEmpty(left) || isEmpty(right))
        {
            while (isEmpty(left) && !isEmpty(right))
            {
                if (!moveOneElement(right, list))
                {
                    return false;
                }
            }
            while (isEmpty(right) && !isEmpty(left))
            {
                if (!moveOneElement(left, list))
                {
                    return false;
                }
            }
        }
        else
        {
            if (code == 0)
            {
                if (strcmp(getName(left), getName(right)) <= 0)
                {
                    if (!moveOneElement(left, list))
                    {
                        return false;
                    }
                }
                else
                {
                    if (!moveOneElement(right, list))
                    {
                        return false;
                    }
                }
            }
            else
            {
                if (strcmp(getNumber(left), getNumber(right)) <= 0)
                {
                    if (!moveOneElement(left, list))
                    {
                        return false;
                    }
                }
                else
                {
                    if (!moveOneElement(right, list))
                    {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

bool mergeSort(List* list, const int code)
{
    if (code != 0 && code != 1)
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
    
    if (!mergeSort(left, code) || !mergeSort(right, code))
    {
        deleteList(&left);
        deleteList(&right);
        return false;
    }

    if (!mergeLists(list, left, right, code))
    {
        deleteList(&left);
        deleteList(&right);
        return false;
    }

    deleteList(&left);
    deleteList(&right);
    return true;
}