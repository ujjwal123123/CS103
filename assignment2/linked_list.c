#include "linked_list.h"

int main()
{
    LIST list1 = NULL;

    prepend(&list1, 5);
    prepend(&list1, 4);
    prepend(&list1, 3);
    prepend(&list1, 2);
    prepend(&list1, 1);
    prepend(&list1, 0);
    append(&list1, 6);
    append(&list1, 7);

    print(list1);
    printf("\n\n%d\n\n", length(list1));

    printUsingRecursion(list1);

    printf("\n\n");

    printUsingRecursion(list1);
}