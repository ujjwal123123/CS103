#include "prob1.h"

//  Implement a stack with an array. The maximum size of the stack is user input.

int main()
{
    int length = 0;
    scanf(" %d", &length);

    STACK stack = newStack(length);

    push(&stack, 5);
    push(&stack, 4);
    push(&stack, 3);

    print(stack);

    pop(&stack);
    pop(&stack);

    print(stack);
}