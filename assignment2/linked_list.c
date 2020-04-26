#include "linked_list.h"

int main()
{
    LIST list1 = NULL;

    // addFirst(&list1, 5);
    addFirst(&list1, 1);
    addFirst(&list1, 2);
    addFirst(&list1, 3);
    addFirst(&list1, 4);
    addFirst(&list1, 5);
    addFirst(&list1, 6);
    addLast(&list1, 0);

    print(list1);
    printf("\n\n%d\n\n", length(list1));

    printUsingRecursion(list1);
    printReverseRecursion(list1);

    // LIST reversed = reverseListOutplace(list1);

    // print(reversed);

    return 0;
}