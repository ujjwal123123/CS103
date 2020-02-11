#include <stdio.h>
#include <stdlib.h>

typedef int DATA;

typedef struct queue {
    int read;
    int write;
    int length;
    int* arr;
} QUEUE;

QUEUE newQueue(int length)
{
    QUEUE* pqueue = (QUEUE*)malloc(sizeof(QUEUE));

    pqueue->read = -1;
    pqueue->write = 0;
    pqueue->length = length;
    pqueue->arr = (DATA*)malloc(length * sizeof(DATA));

    return *pqueue;
}

int enqueue(QUEUE* pqueue, DATA Data)
{
    pqueue->arr[pqueue->write] = Data;
    pqueue->write = (pqueue->write + 1) % pqueue->length;

    printf("%d written to the queue and new write position is %d\n", Data, pqueue->write);

    return 0;
}

DATA dequeue(QUEUE* pqueue)
{
    if (pqueue->write == 0) {
        fprintf(stderr, "Underflow\n");
        return -1;
    }

    DATA ret = pqueue->arr[pqueue->read];

    printf("Read, before: %d; ", pqueue->read);

    pqueue->read = (pqueue->read + 1) % (pqueue->length);

    printf("after: %d\n", pqueue->read);

    return ret;
}

int print(QUEUE queue)
{
    int l = queue.length;

    for (int i = queue.read + 1; i < queue.write; i = (i + 1) % l)
        printf("%d ", queue.arr[i]);

    printf("\n");

    return 0;
}