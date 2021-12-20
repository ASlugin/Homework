#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "List.h"
#include "ListTest.h"
#include "MergeSort.h"
#include "Tests.h"

int main(int argc, char* argv[])
{
    if (!isTestListPassing())
    {
        if (argc <= 1)
        {
            printf("Tests of list failed!");
        }
        return -1;
    }
    if (!areTestsPassing())
    {
        if (argc <= 1)
        {

            printf("Tests failed!");
        }
        return -1;
    }
    if (argc > 1)
    {
        return 0;
    }

    List* list = readDataFromFile("Input.txt");
    if (list == NULL)
    {
        return -1;
    }
    
    printf("Sort by:\n");
    printf("0 - name\n");
    printf("1 - phone number\n");
    printf("Enter code: ");
    SortBy key = -1;
    scanf("%d", &key);
    if (key != name && key != number)
    {
        printf("Incorrect code");
        deleteList(&list);
        return -1;
    }
    
    if (!mergeSort(list, key))
    {
        deleteList(&list);
        return -1;
    }
    
    printList(list);

    deleteList(&list);
    return 0;
}