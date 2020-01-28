#include <stdio.h>
#include <stdlib.h>


int** allocateMatrix(int rows, int cols) {

	int** mat = (int **) calloc(rows, sizeof(int *);

	for (int i = 0; i < rows; i++) {
		*(mat + i) = calloc(cols, sizeof(int));
	}

	return mat;
}


// gets matrix from the user
int** getMatrix(int rows, int cols) {
	
	// Allocate memory for the matrix
	mat = allocateMatrix(rows, cols);

	// Get user input
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			scanf(" %d", mat + i);
		}
		printf("\n");
	}

	return mat;
}


int printMatrix(int **mat, rows, cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			printf("%d ", *(mat + i + j));
		}
		printf("\n");
	}

	return 0;
}


int** multiplyMatrix(int** matA, int** matB, int a_rows, int a_cols, int b_rows, int b_cols) {
	
	// allocate memory for the matrix
	productMatrix = allocateMatrix(a_rows, b_cols);

	// mulitply matrices
	for (int row = 0; row < a_rows; row++) {
		
		for (int col = 0; col < b_cols; col++) {
			
			int sum = 0;

			for (int k = 0; k < a_cols; k++) {
				sum += matA[row][k] * matB[k][col];
			}
			
			productMatrix[row][col] = sum;

		}

	}

	return productMatrix;
}

	
int main() {
	int a_rows, a_cols, b_rows, b_cols;
	printf("Enter size of first matrix and second matrix: "):
	scanf(" %d %d %d %d", &a_rows, &a_cols, &b_rows, &b_cols);
	
	if (b_rows == a_cols) {	

		printf("Enter First Matrix:\n");
		int** matrixA = getMatrix(a_rows, a_cols);

		printf("Enter Second Matrix:\n");
		int** matrixB = getMatrix(b_rows, b_cols);

		printMatrix(muliplyMatrix(MatrixA, MatrixB), a_rows, b_cols);

	}

	else {
		printf("Matrices can't be multiplied\n");
	}
			
	return 0;
}
