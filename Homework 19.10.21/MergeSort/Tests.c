#include "List.h"
#include "MergeSort.h"
#include <string.h>

#define AMOUNT 7
#define SIZE 30

bool testSortByName(void)
{
    List* listTest = readDataFromFile("InputTest.txt");
    if (listTest == NULL)
    {
        return false;
    }

    if (!mergeSort(listTest, 0))
    {
        deleteList(&listTest);
        return false;
    }
    const char nameByName[AMOUNT][SIZE] =
    {
        "a",
        "abfs",
        "ba",
        "bbb",
        "bsa",
        "cbb",
        "cbn"
    };
    const char numberByName[AMOUNT][SIZE] =
    {
        "65",
        "654",
        "103",
        "987",
        "9843",
        "321",
        "123"
    };
    for (int i = 0; i < AMOUNT; ++i)
    {
        char name[SIZE] = {"\0"};
        char number[SIZE] = {"\0"};
        if (!pop(listTest, name, number) || strcmp(name, nameByName[i]) != 0 || strcmp(number, numberByName[i]) != 0)
        {
            deleteList(&listTest);
            return false;
        }
    }
    if (!isEmpty(listTest))
    {
        deleteList(&listTest);
        return false;
    }
    deleteList(&listTest);
    return isEmpty(listTest);
}

bool testSortByNumber(void)
{
    List* listTest = readDataFromFile("InputTest.txt");
    if (listTest == NULL)
    {
        return false;
    }

    if (!mergeSort(listTest, 1))
    {
        deleteList(&listTest);
        return false;
    }
    const char nameByNumber[AMOUNT][SIZE] =
    {
        "ba",
        "cbn",
        "cbb",
        "a",
        "abfs",
        "bsa",
        "bbb"
    };
    const char numberByNumber[AMOUNT][SIZE] =
    {
        "103",
        "123",
        "321",
        "65",
        "654",
        "9843",
        "987"
    };
    for (int i = 0; i < AMOUNT; ++i)
    {
        char name[SIZE] = {"\0"};
        char number[SIZE] = {"\0"};
        if (!pop(listTest, name, number) || strcmp(name, nameByNumber[i]) != 0 || strcmp(number, numberByNumber[i]) != 0)
        {
            deleteList(&listTest);
            return false;
        }
    }
    if (!isEmpty(listTest))
    {
        deleteList(&listTest);
        return false;
    }

    deleteList(&listTest);
    return isEmpty(listTest);
}

bool areTestPassing(void)
{
    return testSortByNumber() && testSortByName();
}