#include "sort.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// insertion sort
void insertionSort(int arr[], const unsigned length)
{
    for (unsigned i = 1; i < length; i++) {
        int key = arr[i];

        // insert key at proper place into sorted array in the left of the key
        unsigned j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

// bubble sort
void bubbleSort(int arr[], const unsigned length)
{
    // bubble sort is the only sorting algorithm in which flag is being used
    bool sorted = false;

    // largest numbers bubble to the right
    for (unsigned i = 0; !sorted && i < length; i++) {
        sorted = true;
        for (unsigned j = 0; j < length - 1 - i; j++)
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                sorted = false;
            }
    }
}

// selection sort
void selectionSort(int arr[], const unsigned length)
{
    /* select minimum number from the right unsorted
     and insert at the end of left sorted array */
    for (unsigned i = 0; i < length - 1; i++) {
        unsigned minIndex = i;
        for (unsigned j = i + 1; j < length; j++)
            if (arr[j] < arr[minIndex])
                minIndex = j;

        swap(&arr[i], &arr[minIndex]);
    }
}

// merge sort
void mergeSort(int arr[], const unsigned length)
{
    if (length == 1)
        return;

    unsigned lengthLeft = length / 2;
    int* left = (int*)malloc(lengthLeft * sizeof(int));

    for (unsigned i = 0; i < lengthLeft; i++)
        left[i] = arr[i];

    unsigned lengthRight = length - length / 2;
    int* right = (int*)malloc(lengthRight * sizeof(int));

    for (unsigned i = 0; i < lengthRight; i++)
        right[i] = arr[lengthLeft + i];

    mergeSort(left, lengthLeft);
    mergeSort(right, lengthRight);
    merge(arr, left, lengthLeft, right, lengthRight);
}

static void merge(int arr[], int left[], int lenLeft, int right[], int lenRight)
{
    int l = 0, r = 0, t = 0;

    while (l < lenLeft && r < lenRight) {
        if (left[l] < right[r])
            arr[t++] = left[l++];
        else
            arr[t++] = right[r++];
    }

    while (l < lenLeft)
        arr[t++] = left[l++];
    while (r < lenRight)
        arr[t++] = right[r++];

    free(left);
    free(right);
}

// quick sort
void quickSort(int arr[], const unsigned size)
{
    // base case
    if (size < 2)
        return;

    int pivot = arr[size / 2];
    unsigned L = 0, U = size - 1;

    // partitioning
    while (L < U) {
        while (arr[L] < pivot)
            L++;
        while (arr[U] > pivot)
            U--;

        swap(&arr[L], &arr[U]);
    }

    quickSort(arr, L); // sort left array
    quickSort(&arr[U + 1], size - L - 1); // sort right array
}

// print the array
static void printArray(int arr[], const unsigned length)
{
    for (unsigned i = 0; i < length; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

static void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int* arr = (int*)malloc(10 * sizeof(int));

    for (unsigned i = 0; i < 10; i++)
        arr[i] = 10 - i;

    // arr[5] = 4;

    printArray(arr, 10);

    quickSort(arr, 10);

    printArray(arr, 10);
}