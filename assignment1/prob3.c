#include <stdio.h>
#include <stdlib.h>

// Allocate memory for the matrix
int** allocateMatrix(int rows, int cols)
{
    int** mat = (int**)calloc(rows, sizeof(int*));
    for (int row = 0; row < rows; row++)
        *(mat + row) = calloc(cols, sizeof(int));

    return mat;
}

// gets matrix from the user
int** getMatrix(int rows, int cols)
{
    int** mat = allocateMatrix(rows, cols);

    // Get user input
    for (int row = 0; row < rows; row++)
        for (int col = 0; col < cols; col++)
            scanf(" %d", *(mat + row) + col);

    printf("\n");

    return mat;
}

int printMatrix(int** mat, int rows, int cols)
{
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++)
            printf("%d ", *(*(mat + row) + col));

        printf("\n");
    }

    return 0;
}

int** multiplyMatrix(int** matA, int** matB, int a_rows, int a_cols, int b_rows, int b_cols)
{
    // allocate memory for the matrix
    int** productMatrix = allocateMatrix(a_rows, b_cols);

    // mulitply matrices
    for (int row = 0; row < a_rows; row++) {

        for (int col = 0; col < b_cols; col++) {

            int sum = 0;
            for (int k = 0; k < a_cols; k++)
                sum += matA[row][k] * matB[k][col];

            productMatrix[row][col] = sum;
        }
    }

    return productMatrix;
}

int freeMatrix(int** mat, int rows)
{
    for (int row = 0; row < rows; row++)
        free(*(mat + row));

    free(mat);
    return 0;
}

int main()
{
    int a_rows, a_cols, b_rows, b_cols;
    printf("Enter size of first matrix and second matrix: ");
    scanf(" %d %d %d %d", &a_rows, &a_cols, &b_rows, &b_cols);

    if (b_rows == a_cols) {

        printf("Enter First Matrix:\n");
        int** matrixA = getMatrix(a_rows, a_cols);

        printf("Enter Second Matrix:\n");
        int** matrixB = getMatrix(b_rows, b_cols);

        int** productMatrix = multiplyMatrix(matrixA, matrixB, a_rows, a_cols, b_rows, b_cols);
        printMatrix(productMatrix, a_rows, b_cols);

        freeMatrix(matrixA, a_rows);
        freeMatrix(matrixB, b_rows);
        freeMatrix(productMatrix, a_rows);

    }

    else
        printf("Matrices can't be multiplied\n");

    return 0;
}
