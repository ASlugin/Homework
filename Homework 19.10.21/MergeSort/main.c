#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "List.h"
#include "ListTest.h"
#include "MergeSort.h"
#include "Tests.h"

int main(void)
{
    if (!areTestListPassing())
    {
        printf("Tests of list failed!");
        return -1;
    }
    if (!areTestPassing())
    {
        printf("Tests failed!");
        return -1;
    }

    List* list = readDataFromFile("Input.txt");
    if (list == NULL)
    {
        return -1;
    }
    
    int code = -1;
    printf("Sort by:\n");
    printf("0 - name\n");
    printf("1 - phone number\n");
    printf("Enter code: ");
    scanf("%d", &code);
    if (code != 0 && code != 1)
    {
        printf("Incorrect code");
        deleteList(&list);
        return -1;
    }
    
    if (!mergeSort(list, code))
    {
        deleteList(&list);
        return -1;
    }
    
    printList(list);

    deleteList(&list);
    return 0;
}