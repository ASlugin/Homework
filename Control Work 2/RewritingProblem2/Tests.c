#include "Tests.h"
#include "List.h"
#include <stddef.h>

#define SIZE 500

bool testPassed(void)
{
    List* list = CreateListAndReadDataFromFile("InputTest.txt");
    if (list == NULL)
    {
        return false;
    }
    list = deleteRepeatingString(list);
    if (list == NULL)
    {
        return false;
    }
    const char result[4][SIZE] = {"aaa", "bb", "cc", "bbb"};
    
    Position* position = createPosition();
    if (position == NULL)
    {
        deleteList(&list);
        return false;
    }
    position = first(list, position);
    while (position != NULL)
    {
        
        position = next(list, position);
    }

    deleteList(&list);
    return true;
}