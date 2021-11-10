#include "ListTest.h"
#include "List.h"
#include <string.h>

bool areTestListPassing(void)
{
    List* listTest = createList();
    if (listTest == NULL)
    {
        return false;
    }

    #define AMOUNT 3
    #define SIZE 30
    const char name[AMOUNT][SIZE] = {"Ivan", "Vasya", "Peter"};
    const char number[AMOUNT][SIZE] = {"654", "1234", "7890"};
    
    for (int i = 0; i < AMOUNT; ++i)
    {
        if (!add(listTest, name[i], number[i]))
        {
            deleteList(&listTest);
            return false;
        }
    }
    if (getLength(listTest) != AMOUNT)
    {
        deleteList(&listTest);
        return false;
    }
   
    for (int i = 0; i < AMOUNT; ++i)
    {
        char nameTest[SIZE] = {"\0"};
        char numberTest[SIZE] = {"\0"};
        if (!pop(listTest, nameTest, numberTest) || strcmp(nameTest, name[i]) != 0 || strcmp(numberTest, number[i]) != 0 || getLength(listTest) != AMOUNT - i - 1)
        {
            deleteList(&listTest);
            return false;
        }
    }
    
    deleteList(&listTest);
    return isEmpty(listTest);
}