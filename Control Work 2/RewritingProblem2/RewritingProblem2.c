#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include "List.h"
#include "Tests.h"
#include <stdio.h>

int main(int argc, char* argv[])
{
    if (!testPassed())
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

    List* list = CreateListAndReadDataFromFile("Input.txt");
    if (list == NULL)
    {
        return -1;
    }
    printList(list);
    printf("\n\n");

    list = deleteRepeatingString(list);
    printList(list);

    deleteList(&list);
    return 0;
}