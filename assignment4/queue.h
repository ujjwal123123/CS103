#include "circular-doubly-linked-list.h"
#include <stdio.h>
#include <stdlib.h>

typedef LIST QUEUE;

QUEUE getQueue()
{
    QUEUE queue = { NULL, NULL };

    return queue;
}

int isQueueEmpty(QUEUE queue)
{
    return isListEmpty(queue);
}

// add to the front
int enqueue(QUEUE* pqueue, DATA Data)
{
    return addLast(pqueue, Data);
}

// remove from the rear
DATA dequeue(QUEUE* pqueue)
{
    return removeFirst(pqueue);
}

// TODO: ask if peek should print front (enqueue) or rear (dequeue)
DATA peek(QUEUE queue)
{
    return getFirst(queue);
}

int printQueue(QUEUE queue)
{
    return print(queue);
}