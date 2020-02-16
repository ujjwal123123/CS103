#include <stdio.h>
#include <stdlib.h>


int** allocateTriMatrix(int size) {
	int** rows = (int **) malloc(size * sizeof(int *));

	int i;
	for (i = 0; i < size; i++) {
		*(rows + i) = (int *) malloc((i + 1) * sizeof(int));
		printf("%p ", rows + i);
	}
	printf("\n");
	return rows;
}

void freeTri(int** ptr, int size) {
	int i;
	for (i = 0; i < size; i++) {
		free(*(ptr + i));
		printf("freed\n");
	}

	free(ptr);

	printf("Successfully freed memory\n");
}

int main() {
	int size;
	scanf(" %d", &size);
	int** ptr = allocateTriMatrix(size);
	printf("The pointer is: %p\n", ptr);

	freeTri(ptr, size);

	return 0;
}
