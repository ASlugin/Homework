#include "TestCyclicList.h"
#include "CyclicList.h"
#include <stddef.h>

#define SIZE 5

bool testDelelete(List* testList, Position* index, int array[])
{
    index = next(first(testList, index));
    if (!deleteElement(testList, index))
    {
        deleteList(&testList);
        deletePosition(&index);
        return false;
    }
    array[1] = 7;
    array[2] = 5;
    array[3] = 3;
    index = first(testList, index);
    for (int i = 0; i < SIZE - 1; ++i)
    {
        if (get(index) != array[i])
        {
            deleteList(&testList);
            deletePosition(&index);
            return false;
        }
        index = next(index);
    }

    index = next(next(first(testList, index)));
    array[0] = 5;
    array[1] = 3;
    array[2] = 4;
    array[3] = 7;
    for (int i = 0; i < SIZE - 1; ++i)
    {
        if (get(index) != array[i])
        {
            deleteList(&testList);
            deletePosition(&index);
            return false;
        }
        index = next(index);
    }
    if (!deleteElement(testList, last(testList, index)) || !deleteElement(testList, last(testList, index))
        || !deleteElement(testList, last(testList, index)))
    {
        deleteList(&testList);
        deletePosition(&index);
        return false;
    }
    if (!isOneElementLeft(testList))
    {
        deleteList(&testList);
        deletePosition(&index);
        return false;
    }

    deletePosition(&index);
    deleteList(&testList);
    return true;
}

bool testCreateAndAdd()
{
    List* testList = createList();
    if (testList == NULL || !isEmpty(testList))
    {
        return false;
    }
    Position* index = createPosition();
    if (index == NULL)
    {
        deleteList(&testList);
        return false;
    }

    int array[SIZE] = {4, 9, 7, 5, 3};
    for (int i = 0; i < SIZE; ++i)
    {
        index = last(testList, index);
        if (!add(testList, index, array[i]))
        {
            deleteList(&testList);
            deletePosition(&index);
            return false;
        }
    }
    index = first(testList, index);
    for (int i = 0; i < SIZE; ++i)
    {
        if (get(index) != array[i])
        {
            deleteList(&testList);
            deletePosition(&index);
            return false;
        }
        index = next(index);
    }
    
    return testDelelete(testList, index, array);
}

bool areTestCyclicListPassing()
{
    return testCreateAndAdd();
}