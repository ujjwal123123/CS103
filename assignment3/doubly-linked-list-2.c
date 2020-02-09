#include "doubly-linked-list-2.h"

int main()
{
    LIST new = NULL;

    addFirst(&new, 5);
    // addFirst(&new, 4);
    // addFirst(&new, 3);
    // addFirst(&new, 2);
    // addFirst(&new, 1);

    print(new);
    printf("Length: %d\n", length(new));

    // LIST new1 = NULL;

    // addFirst(&new1, 6);
    // addFirst(&new1, 7);
    // addFirst(&new1, 8);
    // addFirst(&new1, 9);

    // print(new1);
    // printf("Length: %d\n", length(new1));

    // mergeList(new, new1);

    // printRecursive(new);
    // printReverseRecursion(new);
    // printf("\nLength: %d\n", length(new));

    LIST reversed = reverseOutplace(new);

    printf("Old list is: ");
    print(new);

    printf("Reversed list is: ");
    print(reversed);
    return 0;
}