#include "circular-doubly-linked-list.h"

int main()
{
    LIST list = { NULL, NULL };

    addFirst(&list, 5);
    addFirst(&list, 4);
    addFirst(&list, 3);
    addFirst(&list, 2);

    print(list);

    // removeLast(&list);

    print(list);

    return 0;
}