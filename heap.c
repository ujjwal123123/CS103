#include <malloc.h>
#include <stdio.h>

#define DEFAULT_HEAP_LENGTH 100

void printArray(int* array, int length)
{
    for (int i = 0; i < length; i++)
        printf("%d ", array[i]);

    printf("\n");
}

typedef struct heap {
    int* array;
    int length; //  gives the number of elements in the array
    int heapSize; // how many elements in the heap are stored within the array
} HEAP;

static inline int parent(int i)
{
    return (i - 1) / 2;
}

static inline int left(int i)
{
    return 2 * i + 1;
}

static inline int right(int i)
{
    return 2 * i + 2;
}

static inline void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// HEAP* newHEAP()
// {
//     HEAP* heap = (HEAP*)malloc(sizeof(HEAP));
//     heap->array = (void*)malloc(sizeof(void*) * DEFAULT_HEAP_LENGTH);
//     heap->length = DEFAULT_HEAP_LENGTH;
//     heap->heapSize = 0;
//     return heap;
// }

// int heightHeap(HEAP heap, int index)
// {
//     if (index >= heap.heapSize) {
//         return 0;
//     }

//     return 1 + heightHeap(heap, left(index));
// }

void maxHeapify(HEAP* heap, int parent)
{
    int l = left(parent);
    int r = right(parent);

    int largest = parent;

    int* array = heap->array;

    if (l < heap->heapSize && array[l] > array[parent])
        largest = l;

    if (r < heap->heapSize && array[r] > array[largest])
        largest = r;

    if (largest != parent) {
        swap(&array[largest], &array[parent]);

        maxHeapify(heap, largest);
    }
}

HEAP* buildMaxHeap(int* array, int length)
{
    HEAP* heap = (HEAP*)malloc(sizeof(HEAP));
    heap->length = length;
    heap->heapSize = length;
    heap->array = array;

    for (int i = length / 2; i >= 0; i--)
        maxHeapify(heap, i);

    return heap;
}

void heapSort(int* array, int length)
{
    HEAP* heap = buildMaxHeap(array, length);

    for (int i = length - 1; i >= 1; i--) {
        swap(&array[i], &array[0]);
        heap->heapSize--;
        maxHeapify(heap, 0);
    }

    free(heap);
}

int main()
{
    int arr[] = { 10, 0, 8, 7, 6, 100, 4, 3, 200, 1 };

    heapSort(arr, 10);

    printArray(arr, 10);
}