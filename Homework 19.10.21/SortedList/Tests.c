#include "Tests.h"
#include "List.h"
#include <stddef.h>

bool areTestPassing()
{
    List* testList = createList();
    if (testList == NULL)
    {
        return false;
    }
    #define SIZE 7
    int array[SIZE] = {4, 5, 3, 7, 7, 8, 9};
    int result[SIZE] = {3, 4, 5, 7, 7, 8, 9};
    for (int i = 0; i < SIZE; ++i)
    {
        if (!add(testList, array[i]))
        {
            deleteList(&testList);
            return false;
        }
    }

    Position* index = createPosition();
    if (index == NULL)
    {
        deleteList(&testList);
        return false;
    }
    
    int count = 0;
    index = first(testList, index);
    while (!isThereNoElement(index) && count < SIZE)
    {
        if (get(index) != result[count])
        {
            deleteList(&testList);
            return false;
        }
        index = next(index);
        count++;
    }
    if (count < SIZE || !isThereNoElement(index))
    {
        deleteList(&testList);
        return false;
    }
    
    deletePosition(&index);
    deleteList(&testList);
    return isEmpty(testList);
}