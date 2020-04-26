#include "circular-singly-linked-list.h"

int main()
{
    LIST newlist = { NULL, NULL };
    LIST list2 = { NULL, NULL };

    addFirst(&newlist, 5);
    addFirst(&newlist, 4);
    addFirst(&newlist, 3);
    addFirst(&newlist, 2);
    addFirst(&newlist, 1);

    printList(newlist);

    printf("Removed form the list: %d\n", removeLast(&newlist));

    printList(newlist);

    return 0;
}