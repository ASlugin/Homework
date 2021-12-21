#pragma once

#include <stdbool.h>

// Structure for queue
typedef struct Queue Queue;

// Creates queue and returns pointer to queue
Queue* createQueue(void);

// Adds new element to queue according to the priority
bool enqueue(Queue* queue, const int value, const int priority);

// Returns value of highest priority element of queue
// If queue is empty returns -1
int dequeue(Queue* queue);

// Deletes queue and puts NULL to queue
void deleteQueue(Queue** queue);