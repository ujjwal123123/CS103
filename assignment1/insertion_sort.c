#include <malloc.h>
#include <stdio.h>

int sortArray(int* arr, int length)
{
    for (int i = 1; i < length; i++) {

        int key = arr[i];

        // insert arr[i] into sorted sequence
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }

    return 0;
}

int* getArray(int length)
{
    int* arr = (int*)calloc(length, sizeof(int));

    for (int i = 0; i < length; i++) {
        scanf(" %d", arr + i);
    }

    return arr;
}

int printArray(int* arr, int length)
{
    for (int i = 0; i < length; i++) {
        printf("%d ", *(arr + i));
    }

    printf("\n");

    return 0;
}

int main()
{
    int length;
    scanf(" %d", &length);

    int* arr = getArray(length);
    sortArray(arr, length);
    printArray(arr, length);

    return 0;
}
