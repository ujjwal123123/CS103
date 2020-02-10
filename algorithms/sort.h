#include <stdio.h>
#include <stdlib.h>

int print(int* arr, int length)
{
    for (int i = 0; i < length; i++)
        printf("%d ", arr[i]);

    printf("\n");

    return 0;
}

int insertionSort(int* arr, int length)
{
    for (int i = 1; i < length; i++) {
        int key = arr[i];

        // insert key into the sorted sequece
        int j = i - 1;
        while (j > 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }

    return 0;
}

int bubbleSort(int* arr, int length)
{
    for (int i = 0; i < length - 1; i++) {
        for (int j = length - 1; j > i; j--) {
            if (arr[j] < arr[j - 1]) {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }

    return 0;
}

int selectionSort(int* arr, int length)
{
    for (int i = 0; i < length; i++) {
        int minIndex = i;
        for (int j = i; j < length; j++)
            if (arr[j] < arr[minIndex])
                minIndex = j;

        // swap arr[i] and arr[minIndex]
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }

    return 0;
}

// merge sorted arr1 and arr2, and return a sorted array free both arr1 and arr2
// int* mergeSorted(int* arr1, int len1, int* arr2, int len2)
// {
//     int* fin = (int*)malloc((len1 + len2) * sizeof(int));

//     int i = 0, j = 0, k = 0;
//     while (i < len1 && j < len2) {
//         if (arr1[i] < arr2[j])
//             fin[k++] = arr1[i++];
//         else
//             fin[k++] = arr2[j++];
//     }

//     while (i < len1)
//         fin[k++] = arr1[i++];
//     while (j < len2)
//         fin[k++] = arr2[j++];

//     free(arr1);
//     free(arr2);

//     return fin;
// }

int mergeSorted(int* arr, int low, int high, int highend)
{
    int* sorted = (int*)malloc((highend - low + 1) * sizeof(int));

    int len1 = high - low, len2 = highend - high + 1;

    {
        int i = low, j = high, k = 0;
        while (i < len1 && j < len2) {
            if (arr[i] < arr[j])
                sorted[k++] = arr[i++];
            else
                sorted[k++] = arr[j++];
        }

        while (i < len1)
            sorted[k++] = arr[i++];
        while (j < len2)
            sorted[k++] = arr[j++];
    }

    // copy sorted into arr
    for (int i = 0; i < len1 + len2; i++)
        arr[low + i] = sorted[i];

    free(sorted);

    return 0;
}

int mergeSortHelper(int* arr, int low, int high)
{
    if (low > high)
        return 0;

    int mid = (low + high) / 2;

    mergeSortHelper(arr, low, mid);
    mergeSortHelper(arr, mid + 1, high);
    mergeSorted(arr, low, mid + 1, high);
}

int mergeSort(int* arr, int length)
{
    return mergeSortHelper(arr, 0, length - 1);
}