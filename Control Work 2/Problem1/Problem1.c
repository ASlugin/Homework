#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "List.h"

int main(int argc, char* argv[])
{
    if (argc > 1)
    {
        return 1;
    }
    List* list = createListAndReadDataFromFile("Input.txt");
    if (list == NULL)
    {
        return -1;
    }
    
    if (!swapList(list))
    {
        deleteList(&list);
        return -1;
    }

    printList(list);

    deleteList(&list);
    return 0;
}