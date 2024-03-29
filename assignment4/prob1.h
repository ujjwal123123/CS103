// implement stack using array

#include <stdio.h>
#include <stdlib.h>

typedef int DATA;

typedef struct stack {
    DATA* arr;
    int capacity;
    int filled;
} STACK;

STACK newStackLen(int length)
{
    STACK* stack = (STACK*)malloc(sizeof(STACK));
    stack->arr = (int*)malloc(sizeof(int) * length);
    stack->capacity = length;
    stack->filled = 0;

    return *stack;
}

STACK newStack()
{
    return newStackLen(100);
}

int isFull(STACK* pstack)
{
    return (pstack->filled == pstack->capacity);
}

int push(STACK* pstack, DATA Data)
{
    if (isFull(pstack)) {
        fprintf(stderr, "Stacksoverflow.com\n");
        return -1;
    }

    pstack->arr[pstack->filled++] = Data;

    return 0;
}

int print(STACK stack)
{
    for (int i = 0; i < stack.filled; i++)
        printf("%d ", stack.arr[i]);

    printf("\n");

    return 0;
}

int printStackInt(STACK stack)
{
    return print(stack);
}

int isEmpty(STACK stack)
{
    return (stack.filled == 0);
}

DATA pop(STACK* pstack)
{
    if (isEmpty(*pstack)) {
        fprintf(stderr, "Stack underflow.\n");
        return -1;
    }

    return pstack->arr[--pstack->filled];
}