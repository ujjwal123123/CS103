#include <stdio.h>
#include <stdlib.h>

int printArray(int *arr, int size) {
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
} 

int* findMinMax(int *arr, int size) {
	int minIndex = 0, maxIndex = 0;

	for (int i = 0; i < size; i++) {
		if (arr[minIndex] > arr[i])
			minIndex = i;

		if (arr[maxIndex] < arr[i])
			maxIndex = i;
	}

	int* result = malloc(2 * sizeof(int));
	result[0] = minIndex;
	result[1] = maxIndex;
	return result;
}

int swapMinMax(int *arr, int minIndex, int maxIndex) {
	int temp = arr[minIndex];
	arr[minIndex] = arr[maxIndex];
	arr[maxIndex] = temp;

	return 0; 
}

// part d
int sum(int *arr, int size) {
	int sum = 0;
	for (int i = 0; i < size; i++)
		sum += arr[i];
	return sum;
}

// part e
double avg(int *arr, int size) {
	int sumArr = sum(arr, size);
	return (double) sumArr/size;
}

// part f
int findIndex(int *arr, int size) {
	int no;
	printf("Enter number to find in the array: ");
	scanf(" %d", &no);


	for (int i = 0; i < size; i++)
		if (arr[i] == no)
			return i;

	return -1;
}

// part g
int printIndex(int *arr, int size) {
	printf("Pointer are: ");
	for (int i = 0; i < size; i++) 
		printf("%p ", arr + i);
	printf("\n");

	return 0;
}

int main() {
	int size;
	printf("Enter size of the array: ");
	scanf(" %d", &size);

	int* arr;
	arr = (int *) malloc(size * sizeof(int));

	printf("Enter array: ");
	for (int i = 0; i < size; i++)
		scanf(" %d", &arr[i]);

	// part a
	printArray(arr, size);

	// part b
	int* minMax = (int *) malloc(2 * sizeof(int));
	minMax = findMinMax(arr, size);
	printf("Index of maximum and minimum elements are: ");
	printArray(minMax, 2);

	// part c
	swapMinMax(arr, minMax[0], minMax[1]);
	printf("Swapped array is: ");
	printArray(arr, size);

	// part d
	printf("The sum is: %d\n", sum(arr, size));

	// part e
	printf("The average is: %f\n", avg(arr, size));

	// part f
	printf("The index is: %d\n", findIndex(arr, size));

	// part g
	printIndex(arr, size);


	return 0;
}	
