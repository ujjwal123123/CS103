#include "doubly-linked-list.h"

int main()
{
    LIST new;
    new.first = NULL;
    new.last = NULL;

    prepend(&new, 5);
    prepend(&new, 4);
    prepend(&new, 3);

    print(new);
}