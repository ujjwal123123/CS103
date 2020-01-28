#include "doubly-linked-list-2.h"

int main()
{
    LIST new = NULL;

    addFirst(&new, 5);
    addFirst(&new, 4);
    addFirst(&new, 3);
    addFirst(&new, 2);
    addFirst(&new, 1);

    print(new);
    printf("Length: %d\n", length(new));

    LIST reversed = reverseOutplace(new);
    printf("\n");
    // printf("%d\n", removeByValue(&new, 10));
    printf("\n");

    print(reversed);
    printf("Length: %d\n", length(new));

    return 0;
}