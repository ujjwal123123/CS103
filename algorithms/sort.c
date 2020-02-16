#include "sort.h"
#include <string.h>

#define SIZE 10

int main()
{
    int* arr = malloc(10 * sizeof(int));

    for (int i = 0; i < 10; i++)
        arr[i] = i;

    mergeSort(arr, 10);

    for (int i = 0; i < 10; i++)
        printf("%d ", arr[i]);

    printf("\n");
}