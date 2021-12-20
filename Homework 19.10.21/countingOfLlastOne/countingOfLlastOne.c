#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include "CyclicList.h"
#include "TestCyclicList.h"

// Returns result, else returns error code:
// -1 - list error
// -2 - incorrect input data
int positionOfLatter(int n, int m)
{
    if (n <= 0 || m <= 0)
    {
        return -2;
    }
    List* listOfWarriors = createList();
    if (listOfWarriors == NULL)
    {
        return -1;
    }
    Position* current = createPosition();
    if (current == NULL)
    {
        deleteList(&listOfWarriors);
        return -1;
    }
    
    for (int i = 1; i <= n; ++i)
    {
        if (!add(listOfWarriors, last(listOfWarriors, current), i))
        {
            deleteList(&listOfWarriors);
            deletePosition(&current);
            return -1;
        }
    }

    current = first(listOfWarriors, current);
    while (!isOneElementLeft(listOfWarriors))
    {
        for (int i = 0; i < m - 1; ++i)
        {
            current = next(current);
        }

        if (!deleteElement(listOfWarriors, current))
        {
            deleteList(&listOfWarriors);
            deletePosition(&current);
            return -1;
        }
    }

    int result = get(current);
    deleteList(&listOfWarriors);
    deletePosition(&current);
    return result;
}

bool areTestsPassing()
{
    return positionOfLatter(8, 4) == 6 && positionOfLatter(5, 3) == 4
           && positionOfLatter(9, 1) == 9 && positionOfLatter(3, 0) == -2
           && positionOfLatter(7, 3) == 4;
}

int main(int argc, char* argv[])
{
    if (!areTestCyclicListPassing())
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

    int n = 0;
    printf("Enter amount of warriors: ");
    scanf("%d", &n);
    int m = 0;
    printf("Enter number of warrior to kill: ");
    scanf("%d", &m);
    
    const int result = positionOfLatter(n, m);
    switch (result)
    {
        case -1:
        {
            printf("List error\n");
            return -1;
        }
        case -2:
        {
            printf("Incorrect input data. Enter value n, m > 0\n");
            return -1;
        }
        default:
        {
            printf("Starting position of warrior remaining last: %d\n", result);
            return 0;
        }
    }
    return 0;
}