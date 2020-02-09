#include "doubly-linked-list-2.h"

int main()
{
    LIST new = NULL;

    addFirst(&new, 1);
    addFirst(&new, 2);
    addFirst(&new, 3);
    addFirst(&new, 4);
    addFirst(&new, 5);

    print(new);
    printf("Length: %d\n", length(new));

    sort(&new);

    print(new);
    return 0;
}