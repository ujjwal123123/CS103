#include <malloc.h>
#include <stdio.h>

typedef int DATA;

typedef struct node {
    DATA data;
    struct node* next;
} NODE;

typedef NODE* LIST;

// The function adds a new element to the beginning of the list. This function should be passed pointer to a list
int prepend(LIST* plist, DATA Data)
{
    // temporarily store address stored in list to temp
    NODE* temp = *plist;

    // allocate memory for new node and store address of that in list
    *plist = (LIST)malloc(sizeof(NODE));

    (*plist)->data = Data;
    (*plist)->next = temp;

    return 0;
}

// This function should be passed pointer to a list
int append(LIST* plist, DATA Data)
{
    // find last node in the list
    NODE* pLastNode = *plist;
    while (pLastNode->next) {
        pLastNode = pLastNode->next;
    }
    // pLastNode now points to the last node of the list

    pLastNode->next = (NODE*)malloc(sizeof(NODE));
    pLastNode->next->data = Data;
    pLastNode->next->next = NULL;

    return 0;
}

// returns length of a linked list
int length(LIST list)
{
    int length = 0;

    NODE* node = list;
    while (node) {
        length++;
        node = node->next;
    }

    return length;
}

// deletes first element of the list and returns its value
DATA popFirst(LIST* plist)
{
    // store pointer to second node in temp
    NODE* secondNode = (*plist)->next;
    DATA deletedData = (*plist)->next->data;

    // remove first node from memory
    free(*plist);

    *plist = secondNode;

    return deletedData;
}

DATA popLast(LIST* plist)
{
    NODE* pNode = *plist;

    while (pNode->next->next) {
        pNode = pNode->next;
    }
    // now Node points to the second last node in the original list

    // store data to be deleted
    DATA deletedData = pNode->next->data;

    free(pNode->next);

    pNode->next = NULL;

    return deletedData;
}

int mutate(LIST* plist, DATA Data, int index)
{
    NODE* pNode = *plist;

    while (index--) {
        if (pNode->next) {
            pNode = pNode->next;
        } else {
            fprintf(stderr, "Array index passed to %s is out of bound\n", __func__);
            return 1;
        }
    }

    DATA temp = pNode->data;
    pNode->data = Data;

    return temp;
}

// Add node at the index passed to the function
int add(LIST* plist, DATA Data, int index)
{
    NODE** ppNode = plist;

    while (index--) {
        if ((*ppNode)->next) {
            ppNode = &((*ppNode)->next);
        } else {
            fprintf(stderr, "Array index passed to %s is out of bound\n", __func__);
            return 1;
        }
    }

    NODE* temp = *ppNode;

    *ppNode = (NODE*)malloc(sizeof(NODE));
    (*ppNode)->data = Data;
    (*ppNode)->next = temp;

    return 0;
}

// Remove node at index passed to the function
DATA pop(LIST* plist, int index)
{
    NODE** ppNode = plist;

    while (index--) {
        if ((*ppNode)->next) {
            ppNode = &((*ppNode)->next);
        } else {
            fprintf(stderr, "Array index passed to %s is out of bound\n", __func__);
            return 1;
        }
    }

    NODE* temp = (*ppNode)->next;
    DATA deletedData = (*ppNode)->data;

    free(*ppNode);
    *ppNode = temp;

    return deletedData;
}

// Returns data stored in a node
DATA getData(LIST list, int index)
{
    NODE* pnode = list;

    while (index--) {
        if (pnode->next) {
            pnode = pnode->next;
        } else {
            fprintf(stderr, "Array index passed to %s is out of bound\n", __func__);
            return 1;
        }
    }

    return (pnode->data);
}

// // Write a function to remove the first occurrence of a given data of the list
// int pop_data(LIST* plist, DATA Data)
// {
//     NODE** ppNode = plist;

//     while ((*ppNode)->data != Data) {
//         if (!((*ppNode)->next)) {
//             return 1;
//         }
//         ppNode = &((*ppNode)->next);
//     }

//     return 0;
// }

// print elements of the list
int print(LIST list)
{
    if (!list) {
        fprintf(stderr, "The list is empty.\n");
        return 1;
    }

    int index = 0;
    // Node is stored in stack
    NODE* Node = list;
    while (Node) {
        printf("[%d]: %d  (%p) (%p)\n", index++, Node->data, &Node, &(Node->data));

        Node = Node->next;
    }

    return 0;
}
