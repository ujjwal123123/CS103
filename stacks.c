#include "stacks.h"

int main()
{
    STACK output = NULL;

    // push(&output, 5);
    // push(&output, 6);
    // push(&output, 7);

    prints(output);

    pop(&output);

    prints(output);

    pop(&output);

    prints(output);
}