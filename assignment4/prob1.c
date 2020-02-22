#include "prob1.h"

//  Implement a stack with an array. The maximum size of the stack is user input.

int main()
{
    STACK stack = newStack();

    push(&stack, 5);
    push(&stack, 4);
    push(&stack, 3);
    push(&stack, 2);

    print(stack);

    printf("%d\n", pop(&stack));
    printf("%d\n", pop(&stack));
    printf("%d\n", pop(&stack));

    print(stack);

    return 0;
}