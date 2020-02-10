#include "doubly-linked-list-2.h"

int main()
{
    // int i = 0;

    LIST new = NULL;

    addFirst(&new, 1);
    addFirst(&new, 2);
    addFirst(&new, 3);
    addFirst(&new, 4);

    print(new);

    removeLast(&new);

    print(new);

    addFirst(&new, 5);
    addFirst(&new, 6);
    addFirst(&new, 7);

    // for (int i = 0; i < 100; i++)
    //     addFirst(&new, i);

    print(new);
    printf("Length: %d\n", length(new));

    // sort(&new);

    // print(new);
    return 0;
}