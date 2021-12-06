#include "List.h"
#include "MergeSort.h"
#include <string.h>

#define AMOUNT 7
#define SIZE 30

bool areTestsPassing(void)
{
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

    for (SortBy key = name; key <= number; ++key)
    {
        List* listTest = readDataFromFile("InputTest.txt");
        if (listTest == NULL)
        {
            return false;
        }
        if (!mergeSort(listTest, key))
        {
            deleteList(&listTest);
            return false;
        }

        for (int i = 0; i < AMOUNT; ++i)
        {
            char nameTest[SIZE] = {'\0'};
            char numberTest[SIZE] = {'\0'};
            if (key == name && (!pop(listTest, nameTest, numberTest) || strcmp(nameTest, nameByName[i]) != 0 || strcmp(numberTest, numberByName[i]) != 0)
                || key == number && (!pop(listTest, nameTest, numberTest) || strcmp(nameTest, nameByNumber[i]) != 0 || strcmp(numberTest, numberByNumber[i]) != 0))
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
    }
    return true;
}