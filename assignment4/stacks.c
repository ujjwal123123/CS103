#include "stacks.h"

int main()
{
    STACK output = NULL;

    push(&output, 5);
    push(&output, 6);
    push(&output, 7);

    printStackInt(output);

    printStackInt(reverse(output));

    printStackInt(output);
}