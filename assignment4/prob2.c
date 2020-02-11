#include "prob2.h"

int main()
{
    QUEUE queue = newQueue(5);

    enqueue(&queue, 5);
    enqueue(&queue, 4);

    print(queue);

    return 0;
}