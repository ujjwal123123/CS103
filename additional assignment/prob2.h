#include <stdio.h>
#include <stdlib.h>

int print(int* arr, int length)
{
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

// TODO: For some reason, this code is not working
// Sort array in place using insertion sort
// int insertionSort(int* arr, int length)
// {
//     for (int i = 1; i < length; i++) {
//         if (arr[i] < arr[i - 1]) {
//             int key = arr[i];

//             int j = i - 1;

//             while (1) {
//                 arr[j + 1] = arr[j];

//                 if (arr[j] > key) {
//                     break;
//                 }

//                 j--;
//             }

//             arr[j] = key;
//         }
//     }

//     return 0;
// }

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

// //TODO: for some reason this does not work
// int bubbleSort(int* arr, int length)
// {
//     int i = 1;
//     while (i < length) {
//         if (arr[i] < arr[i - 1]) {
//             int temp = arr[i];
//             arr[i] = arr[i - 1];
//             arr[i - 1] = temp;
//         } else {
//             i++;
//         }
//     }

//     return 0;
// }

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