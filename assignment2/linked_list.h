#include <malloc.h>
#include <stdio.h>

typedef int DATA;

typedef struct node {
    DATA data;
    struct node* next;
} NODE;

typedef NODE* LIST;

NODE* newNode(DATA Data, NODE* next)
{
    NODE* new = (NODE*)malloc(sizeof(NODE));
    new->data = Data;
    new->next = next;

    return new;
}

// The function adds a new element to the beginning of the list. This function should be passed pointer to a list
int addFirst(NODE** ppnode, DATA Data)
{
    *ppnode = newNode(Data, *ppnode);

    return 0;
}

// This function should be passed pointer to a list
int addLast(LIST* plist, DATA Data)
{
    NODE* new = newNode(Data, NULL);

    while (*plist)
        plist = &((*plist)->next);

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
DATA removeFirst(NODE** ppnode)
{
    // check if the list is empty
    if (*ppnode) {

        // store pointer to second node in temp
        NODE* secondNode = (*ppnode)->next;
        DATA deletedData = (*ppnode)->next->data;

        // remove first node from memory
        free(*ppnode);

        *ppnode = secondNode;

        return deletedData;

    } else {
        fprintf(stderr, "The list is already empty. It is underflow.\n");
        return 1;
    }
}

DATA removeLast(LIST* plist)
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
DATA removeNode(LIST* plist, int index)
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

    if (!list)
        return 0;

    printf("[%d]: %d  (%p) (%p)\n", index++, list->data, &list, &(list->data));

    return printUsingRecursion(list->next);
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

// insert an element into a sorted list such that the final list is also sorted
int insertSorted(NODE** ppnode, DATA key)
{
    if ((*ppnode)->data > key)
        return addFirst(ppnode, key);

    NODE* pnode = *ppnode;
    while (pnode->next && pnode->next->data < key)
        pnode = pnode->next;

    pnode->next = newNode(key, pnode->next);

    return 0;
}

// sort the list using selection sort
int sortList(NODE** ppnode)
{
    for (NODE* i = *ppnode; i->next; i = i->next) {

        // find min
        NODE* min = i;
        for (NODE* j = i->next; j; j = j->next)
            if (j->data < i->data)
                min = j;

        // swap min and i
        DATA temp = i->data;
        i->data = min->data;
        min->data = temp;
    }

    return 0;
}

// reverse list outplace
LIST reverseListOutplace(LIST list)
{
    LIST reversed = NULL;
    for (NODE* pnode = list; pnode; pnode = pnode->next)
        addFirst(&reversed, pnode->data);

    return reversed;
}

// TODO: how does this work
// reverse list using recursion
LIST reverseRecursion(LIST oldList, LIST newList)
{
    if (oldList == NULL)
        return newList;

    NODE* pnode = oldList;
    oldList = oldList->next;
    pnode->next = newList;

    return reverseRecursion(oldList, pnode);
}