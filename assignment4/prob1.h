#include <stdio.h>
#include <stdlib.h>

typedef int DATA;

typedef struct stack {
    int* arr;
    int len;
    int filled;
} STACK;

STACK newStack(int length)
{
    int* array = (int*)malloc(sizeof(int) * length);

    STACK* stack = (STACK*)malloc(sizeof(STACK));
    stack->arr = array;
    stack->len = length;
    stack->filled = 0;

    return *stack;
}

int push(STACK* stack, DATA Data)
{
    if (stack->filled == stack->len) {
        fprintf(stderr, "Stack overflow.\n");
        return -1;
    }

    *(stack->arr + stack->filled) = Data;

    stack->filled++;

    return 0;
}

int print(STACK stack)
{
    for (int i = 0; i < stack.filled; i++)
        printf("%d ", stack.arr[i]);

    printf("\n");

    return 0;
}

DATA pop(STACK* stack)
{
    if (stack->filled == 0) {
        fprintf(stderr, "Stack underflow.\n");
        return -1;
    }

    DATA ret = *(stack->arr + stack->filled - 1);

    stack->filled--;

    return ret;
}