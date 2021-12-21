#define _CRT_SECURE_NO_WARNINGS
#include "Queue.h"
#include "Tests.h"
#include <stdio.h>

int main(int argc, char* argv[])
{
    if (!testsQueuePassed())
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

    printf("Tests passed!\n");
    
    Queue* queue = createQueue();
    if (queue == NULL)
    {
        printf("Allocation error\n");
        return -1;
    }
    printf("Command for queue:\n");
    printf("0 - exit\n");
    printf("1 - add new element to queue\n");
    printf("2 - take highest priority element of queue\n");
    printf("3 - print all element of queue\n");

    while (true)
    {
        int code = -1;
        printf("Enter command: ");
        scanf("%d", &code);
        switch (code)
        {
            case 0:
            {
                deleteQueue(&queue);
                return 0;
            }
            case 1:
            {
                int value = -1;
                int priority = 0;
                printf("Enter value: ");
                scanf("%d", &value);
                if (value < 0)
                {
                    printf("Value must be >= 0\n");
                    break;
                }
                printf("Enter priority for given value: ");
                scanf("%d", &priority);
                if (!enqueue(queue, value, priority))
                {
                    printf("Enqueue error\n");
                    deleteQueue(&queue);
                    return -1;
                }
                printf("Added\n");
                break;
            }
            case 2:
            {
                int result = dequeue(queue);
                if (result == -1)
                {
                    printf("Queue os empmty!\n");
                    break;
                }
                printf("Highest priority element of queue: %d", result);
                break;
            }
            case 3:
            {
                int value = dequeue(queue);
                while (value != -1)
                {
                    printf("%d ", value);
                    value = dequeue(queue);
                }
            }
            default:
            {
                printf("Incorrect command!\n");
                break;
            }
        }
    }
}