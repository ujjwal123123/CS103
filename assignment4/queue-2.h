#include "stacks.h"

typedef struct queue {
    STACK s1;
    STACK s2;
} QUEUE;

QUEUE newQueue()
{
    QUEUE* new = (QUEUE*)malloc(sizeof(QUEUE));
    new->s1 = NULL;
    new->s2 = NULL;
    return *new;
}

// enqueue is cheaper
int enqueue(QUEUE* pqueue, DATA data)
{
    return push(&(pqueue->s1), data);
}

int printQueue(QUEUE queue)
{
    return printStackInt(queue.s1);
}

int dequeue(QUEUE* pqueue)
{
    while (!isEmpty(pqueue->s1))
        push(&(pqueue->s2), pop(&(pqueue->s1)));

    pop(&(pqueue->s2));

    while (!isEmpty(pqueue->s2))
        push(&(pqueue->s1), pop(&(pqueue->s2)));

    return 0;
}