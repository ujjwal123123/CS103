#include <stdio.h>
#include <stdlib.h>

#define DATA int

typedef struct node {
    DATA data;
    struct node* next;
} NODE;

NODE** initializeList()
{
    NODE* pnode = NULL;
    NODE** ppnode = &pnode;

    return ppnode;
}

// Part a: add an element to the beginning of the list
int addBeginning(NODE** ppnode, DATA numb)
{
    NODE* temp = *ppnode;

    NODE* pnode = *ppnode;

    pnode = (NODE*)malloc(sizeof(NODE));

    pnode->data = numb;
    pnode->next = temp;

    printf("Added to list: %d\n", *ppnode->next);

    return 0;
}

// Part b: print the elements in the list
int printList(NODE** ppnode)
{

    NODE* pnode = *ppnode;

    while (pnode) {
        printf("%d ", pnode->data);
        pnode = pnode->next;
    }
    printf("\n");

    return 0;
}

// Part c: count the number of elements in the list
int getLength(NODE** ppnode)
{
    NODE* pnode = *ppnode;
    int length = 0;

    while (pnode) {
        length++;
        pnode = pnode->next;
    }

    return length;
}

// Part d: remove the first element of the list
DATA removeFirst(NODE** ppnode)
{

    DATA removedValue = (*ppnode)->data;
    NODE* pointerTofree = *ppnode;

    *ppnode = (*ppnode)->next;

    free(pointerTofree);

    printf("%d removed from the list\n", removedValue);

    return removedValue;
}

// Part e: add an element at the end of the list
int addLast(NODE** ppnode, DATA Data)
{
    NODE* pnode = *ppnode;

    while (pnode->next) {
        pnode = pnode->next;
    }

    pnode->next = (NODE*)malloc(sizeof(NODE));

    pnode = pnode->next;

    pnode->data = Data;
    pnode->next = NULL;

    return 0;
}

int main()
{
    NODE** list = initializeList();

    char option = 1;
    DATA data;

    printf("a for adding data to the beginning\n");
    printf("b for printing the list\n");
    printf("c for length of the list\n");
    printf("d for removing the last\n");
    printf("e add data to the end\n");

    while (1) {
        printf("\nEnter an option: ");
        scanf(" %c", &option);

        switch (option) {
        case 'a':
            // add an element at the beginning of the list
            printf("Enter element to be added: ");
            scanf(" %d", &data);
            addBeginning(list, data);
            break;
        case 'b':
            // print the elements in the list
            printList(list);
            break;
        case 'c':
            // count the number of elements in the list
            printf("Length of the list is; %d\n", getLength(list));
            break;
        case 'd':
            // remove the first element of the list
            removeFirst(list);
            break;
        case 'e':
            // add an element at the end of the list
            printf("Enter data to add: ");
            scanf(" %d", &data);
            addLast(list, data);
            break;
        }
    }

    return 0;
}
