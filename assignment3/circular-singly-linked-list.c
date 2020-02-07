#include "circular-singly-linked-list.h"

int main()
{
    LIST list = { NULL, NULL };

    addFirst(&list, 5);
    addFirst(&list, 4);
    addFirst(&list, 3);
    addFirst(&list, 2);
    addFirst(&list, 1);

    printList(list);

    printf("Removed form the list: %d\n", removeLast(&list));

    printList(list);

    return 0;
}