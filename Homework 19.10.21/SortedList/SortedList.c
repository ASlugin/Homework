#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include "List.h"
#include "Tests.h"

int main(int argc, char* argv[])
{
    if (!areTestPassing())
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

    List* sortedList = createList();
    if (sortedList == NULL)
    {
        printf("createList: Allocation error");
        return -1;
    }

    printf("Commands for a sorted list:\n");
    printf("0 - exit\n");
    printf("1 - add a value to the sorted list\n");
    printf("2 - remove a value from the list\n");
    printf("3 - print the list\n");
    
    while (true)
    {
        int code = 0;
        printf("Enter command: ");
        scanf("%d", &code);
        switch (code)
        {
            case 0:
            {
                deleteList(&sortedList);
                return 0;
            }
            case 1:
            {
                int newValue = 0;
                printf("Enter value to add: ");
                scanf("%d", &newValue);
                if (!add(sortedList, newValue))
                {
                    printf("add: Allocation error");
                    deleteList(&sortedList);
                    return -1;
                }
                break;
            }
            case 2:
            {
                if (isEmpty(sortedList))
                {
                    printf("List is empty\n");
                    break;
                }
                int value = 0;
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteValue(sortedList, value);
                printf("All elements equal to %d are removed\n", value);
                break;
            }
            case 3:
            {
                if (isEmpty(sortedList))
                {
                    printf("List is empty\n");
                    break;
                }
                printList(sortedList);
                break;
            }
            default:
            {
                printf("Incorrect command\n");
                break;
            }
        }
    }
    return 0;
}