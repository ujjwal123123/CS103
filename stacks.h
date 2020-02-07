#include <stdio.h>
#include <stdlib.h>

typedef char DATA;

typedef struct node {
    DATA data;
    struct node* next;
} NODE;

typedef NODE* STACK;

DATA pop(STACK* head)
{
    if (!(*head)) {
        fprintf(stderr, "The stack is already empty. Call to pop failed.\n");
        return -1;
    }

    DATA retValue = (*head)->data;

    NODE* toFree = *head;

    (*head) = (*head)->next;
    free(toFree);

    return retValue;
}

int push(STACK* head, DATA Data)
{
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    newNode->next = *head;
    newNode->data = Data;

    *head = newNode;

    return 0;
}

int prints(STACK stack)
{
    if (!stack) {
        fprintf(stderr, "The stack is empty.\n");
    }
    while (stack) {
        printf("%c ", stack->data);

        if (stack->next == NULL)
            break;

        stack = stack->next;
    }
    printf("\n");

    return 0;
}

DATA peek(STACK stack)
{
    if (stack)
        return (stack->data);
    else {
        fprintf(stderr, "Call to peek failed. Stack is empty.\n");
        return -1;
    }
}

int isEmpty(STACK stack)
{
    if (!stack)
        return 1;
    else
        return 0;
}

int emptyStack(STACK stack)
{
    while (stack) {
        if (stack->next) {
            free(stack->next);
            stack = stack->next;
        }
    }

    return 0;
}

NODE* reverse(NODE* head)
{
    NODE* pnode = head;

    STACK reversed = NULL;
    while (pnode) {
        push(&reversed, pnode->data);

        if (pnode->next)
            pnode = pnode->next;
        else
            break;
        
    }

    return reversed;
}