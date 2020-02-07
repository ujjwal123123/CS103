#include <malloc.h>
#include <stdio.h>

typedef int DATA;

typedef struct node {
    DATA data;
    struct node* next;
} NODE;

typedef NODE* LIST;

// The function adds a new element to the beginning of the list. This function should be passed pointer to a list
int addFirst(LIST* plist, DATA Data)
{
    NODE* new = (NODE*)malloc(sizeof(NODE));
    new->data = Data;
    new->next = *plist;

    *plist = new;

    return 0;
}

// This function should be passed pointer to a list
int addLast(LIST* plist, DATA Data)
{
    NODE* new = (NODE*)malloc(sizeof(NODE));
    new->data = Data;
    new->next = NULL;

    while (*plist) {
        plist = &((*plist)->next);
    }

    *plist = new;

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
DATA deleteFirst(LIST* plist)
{
    // check if the list is empty
    if (*plist) {

        // store pointer to second node in temp
        NODE* secondNode = (*plist)->next;
        DATA deletedData = (*plist)->next->data;

        // remove first node from memory
        free(*plist);

        *plist = secondNode;

        return deletedData;

    } else {
        fprintf(stderr, "The list is already empty. It is underflow.\n");
        return 1;
    }
}

DATA deleteLast(LIST* plist)
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
DATA delete(LIST* plist, int index)
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

// merge two lists
int mergeList(LIST* plist1, LIST* plist2)
{
    while (*plist1) {
        plist1 = &((*plist1)->next);
    }

    *plist1 = *plist2;

    return 0;
}

// print lists using recursion
int printUsingRecursion(LIST list)
{
    // TODO: this function can only be called at most once else indices are printed incorrectly
    static int index = 0;

    if (list) {
        printf("[%d]: %d  (%p) (%p)\n", index++, list->data, &list, &(list->data));

        if (list->next) {
            list = list->next;

            return printUsingRecursion(list);
        } else {
            return 0;
        }
    }

    return 0;
}

// print list in reverse order using recursion
int printReverseRecursion(NODE* pnode)
{
    if (pnode == NULL)
        return 0;

    printReverseRecursion(pnode->next);

    printf("%d ", pnode->data);

    return 0;
}

// // reverse list using recursion
// NODE* reverseListRecursion(NODE* pnode) 
// {
//     // copy pasted from geeksforgeeks

//     if (pnode == NULL)
//         return NULL;
//     if (pnode->next == NULL) {
//         head = pnode;
//         return pnode;
//     }

//     NODE* temp = reverseListRecursion(pnode->next);
//     temp->next = pnode;
//     pnode->next = NULL

//     return pnode

// }