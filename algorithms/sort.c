#include "sort.h"
#include <string.h>

#define SIZE 10

int main()
{
    int* arr = malloc(SIZE * sizeof(int));
    memcpy(arr, (int[]) { 1, 2, 5, 8, 9, 9, 9, 12, 13, 18 }, SIZE * sizeof(int));

    print(arr, 10);

    int* brr = malloc(SIZE * sizeof(int));
    memcpy(brr, (int[]) { 2, 3, 5, 4, 2, 3, 9, 10, 13, 14 }, SIZE * sizeof(int));

    print(brr, 10);

    // print(mergeSorted(arr, 10, brr, 10), 20);
    // selectionSort(arr, 10);
    // print(arr, 10);
    mergeSort(brr, 10);
    print(brr, 10);
}