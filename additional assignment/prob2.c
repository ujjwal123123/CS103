#include "prob2.h"
#include <string.h>

#define SIZE 10

int main()
{
    int* arr = malloc(SIZE * sizeof(int));
    memcpy(arr, (int[]) { 1, 2, 5, 4, 6, 1, 9, 6, 3, 8 }, SIZE * sizeof(int));
    print(arr, 10);

    selectionSort(arr, 10);
    print(arr, 10);
}