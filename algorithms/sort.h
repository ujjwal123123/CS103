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

int merge(int* arr, int* aux, int low, int high, int highend)
{
    int len1 = high - low, len2 = highend - high + 1;

    {
        int i = low, j = high, k = low;
        while (i < len1 && j < len2) {
            if (aux[i] < aux[j])
                arr[k++] = aux[i++];
            else
                arr[k++] = aux[j++];
        }

        while (i < len1)
            arr[k++] = aux[i++];
        while (j < len2)
            arr[k++] = aux[j++];
    }

    // // copy sorted into arr
    // for (int i = 0; i < len1 + len2; i++)
    //     arr[i] = aux[i];

    return 0;
}

int mergeSortHelper(int* arr, int* aux, int low, int high)
{
    if (low >= high)
        return 0;

    int mid = (low + high) / 2;

    mergeSortHelper(arr, aux, low, mid);
    mergeSortHelper(arr, aux, mid + 1, high);
    merge(arr, aux, low, mid + 1, high);

    return 0;
}

int mergeSort(int* arr, int length)
{
    int* aux = (int*)malloc(sizeof(int) * length);
    return mergeSortHelper(arr, aux, 0, length - 1);
}