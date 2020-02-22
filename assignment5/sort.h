#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int length)
{
    for (int i = 0; i < length; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertionSort(int arr[], int length)
{
    for (int i = 1; i < length; i++) {
        int key = arr[i];

        // insert key into proper place
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

void bubbleSort(int arr[], int length)
{
    char sorted = 0;

    for (int i = 0; !sorted && i < length; i++) {
        sorted = 1;
        for (int j = 0; j < length - 1 - i; j++)
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                sorted = 0;
            }
    }
}

void selectionSort(int arr[], int length)
{
    for (int i = 0; i < length - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < length; j++)
            if (arr[j] < arr[minIndex])
                minIndex = j;

        swap(&arr[i], &arr[minIndex]);
    }
}

// void sort(char *, const unsigned, const unsigned, int (*)(char *, char *));

void merge(int arr[], int left[], int lenLeft, int right[], int lenRight)
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

void mergeSort(int arr[], int length)
{
    if (length == 1)
        return;

    int lengthLeft = length / 2;
    int* left = (int*)malloc(lengthLeft * sizeof(int));

    for (int i = 0; i < lengthLeft; i++)
        left[i] = arr[i];

    int lengthRight = length - length / 2;
    int* right = (int*)malloc(lengthRight * sizeof(int));

    for (int i = 0; i < lengthRight; i++)
        right[i] = arr[lengthLeft + i];

    mergeSort(left, lengthLeft);
    mergeSort(right, lengthRight);
    merge(arr, left, lengthLeft, right, lengthRight);
}

// // sort an array of any structure concerning any of its member variables
// void sort(char* a, const unsigned, const unsigned, int (*)(char*, char*))
// {
// }

// typedef struct st {
//     int key;
//     int Data;
// } STRUCT;

// void sortGeneric(void* arr[], int length)
// {
//     for (int i = 0; i < length; i++) {
//         for (int j = 0; j < length - 1 - i; j++) {
//             swap(&arr[j], &arr[j + 1]);
//         }
//     }
// }