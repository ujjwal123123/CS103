// Implementation of stack with singly linked list

#include <stdio.h>
#include <stdlib.h>

typedef int DATA;

typedef struct node {
    DATA data;
    struct node* next;
} NODE;

typedef NODE* STACK;

NODE* newNode(DATA Data, NODE* next)
{
    NODE* new = (NODE*)malloc(sizeof(NODE));
    new->data = Data;
    new->next = next;
    return new;
}

STACK newStack()
{
    return NULL;
}

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
    *head = newNode(Data, *head);
    return 0;
}

int printStackChar(STACK stack)
{
    if (!stack) {
        fprintf(stderr, "The stack is empty.\n");
        return -1;
    }

    for (NODE* pnode = stack; pnode; pnode = pnode->next)
        printf("%c ", pnode->data);

    printf("\n");

    return 0;
}

int printStackInt(STACK stack)
{
    if (!stack) {
        fprintf(stderr, "The stack is empty.\n");
        return -1;
    }

    for (NODE* pnode = stack; pnode; pnode = pnode->next)
        printf("%d ", pnode->data);

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
    return (!stack);
}

static int freeStackHelper(NODE* pnode)
{
    if (pnode && pnode->next)
        freeStackHelper(pnode->next);

    free(pnode);
    return 0;
}

int freeStack(NODE** ppnode)
{
    freeStackHelper(*ppnode);
    *ppnode = NULL;
    return 0;
}

NODE* reverse(NODE* head)
{
    STACK reversed = NULL;

    for (NODE* pnode = head; pnode; pnode = pnode->next)
        push(&reversed, pnode->data);

    return reversed;
}

int length(STACK stack)
{
    int length = 0;

    for (NODE* pnode = stack; pnode != NULL; pnode = pnode->next)
        length++;

    return length;
}