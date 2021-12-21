#include "Queue.h"
#include <stdlib.h>

typedef struct Node
{
    int value;
    int priority;
    struct Node* previous;
    struct Node* next;
} Node;

typedef struct Queue
{
    Node* first;
    Node* last;
} Queue;

Queue* createQueue(void)
{
    return calloc(1, sizeof(Queue));
}

bool enqueue(Queue* queue, const int value, const int priority)
{
    if (queue == NULL)
    {
        return false;
    }
    Node* newNode = calloc (1, sizeof(Node));
    if (newNode == NULL)
    {
        return false;
    }
    newNode->value = value;
    newNode->priority = priority;

    if (queue->first == NULL || queue->last == NULL)
    {
        queue->first = newNode;
        queue->last = newNode;
        return true;
    }

    Node* nodeAfterWhichInsert = queue->last;
    while (nodeAfterWhichInsert != NULL && nodeAfterWhichInsert->priority < newNode->priority)
    {
        nodeAfterWhichInsert = nodeAfterWhichInsert->previous;
    }
    
    if (nodeAfterWhichInsert == NULL)
    {
        newNode->next = queue->first;
        queue->first->previous = newNode;
        queue->first = newNode;
        return true;
    }
    
    newNode->next = nodeAfterWhichInsert->next;
    newNode->previous = nodeAfterWhichInsert;
    nodeAfterWhichInsert->next = newNode;
    if (nodeAfterWhichInsert == queue->last)
    {
        queue->last = newNode;
    }
    return true;
}

int dequeue(Queue* queue)
{
    if (queue == NULL || queue->first == NULL)
    {
        return -1;
    }
    
    int result = queue->first->value;
    Node* nodeForDelete = queue->first;
    queue->first = queue->first->next;
    free(nodeForDelete);
    return result;
}

void deleteQueue(Queue** queue)
{
    if (*queue == NULL)
    {
        return;
    }

    Node* nodeForDelete = (*queue)->first;
    while (nodeForDelete != NULL)
    {
        (*queue)->first = nodeForDelete->next;
        free(nodeForDelete);
        nodeForDelete = (*queue)->first;
    }
    free(*queue);
    *queue = NULL;
}