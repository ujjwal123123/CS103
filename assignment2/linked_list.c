#include "linked_list.h"

int main()
{
    LIST list1 = NULL;

    addFirst(&list1, 5);
    addFirst(&list1, 4);
    addFirst(&list1, 3);
    addFirst(&list1, 2);
    addFirst(&list1, 1);
    addFirst(&list1, 0);
    addLast(&list1, 6);
    addLast(&list1, 7);

    print(list1);
    printf("\n\n%d\n\n", length(list1));

    reverseListRecursion(list1);

    print(list1);

    return 0;
}