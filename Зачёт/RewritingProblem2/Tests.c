#include "Tests.h"
#include "Queue.h"
#include <stddef.h>

#define AMOUNT 10

bool testsQueuePassed(void)
{
    Queue* queue = createQueue();
    if (queue == NULL)
    {
        return false;
    }
    int arrayValue[AMOUNT] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arrayPriority[AMOUNT] = {10, 5, 2, 7, 5, 10, 17, 19, 2, 1};
    int result[AMOUNT] = {8, 7, 1, 6, 4, 2, 5, 3, 9, 10};
    
    for (int i = 0; i < AMOUNT; ++i)
    {
        if (!enqueue(queue, arrayValue[i], arrayPriority[i]))
        {
            deleteQueue(&queue);
            return false;
        }
    }
    for (int i = 0; i < AMOUNT; ++i)
    {
        if (dequeue(queue) != result[i])
        {
            deleteQueue(&queue);
            return false;
        }
    }
    deleteQueue(&queue);
    return true;
}