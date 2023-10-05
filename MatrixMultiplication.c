#include <stdio.h>

// Function to multiply two matrices
void matrix_multiply(int mat1[][3], int mat2[][3], int result[][3], int rows1, int cols1, int cols2) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

// Function to display a matrix
void display_matrix(int mat[][3], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows1, cols1, rows2, cols2;

    // Input the dimensions of the first matrix
    printf("Enter the number of rows and columns for Matrix 1: ");
    scanf("%d %d", &rows1, &cols1);

    // Input the dimensions of the second matrix
    printf("Enter the number of rows and columns for Matrix 2: ");
    scanf("%d %d", &rows2, &cols2);

    if (cols1 != rows2) {
        printf("Matrix multiplication is not possible. The number of columns in Matrix 1 must be equal to the number of rows in Matrix 2.\n");
        return 1;
    }

    int matrix1[rows1][cols1];
    int matrix2[rows2][cols2];
    int result[rows1][cols2];

    // Input elements of Matrix 1
    printf("Enter elements of Matrix 1:\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    // Input elements of Matrix 2
    printf("Enter elements of Matrix 2:\n");
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    printf("Matrix 1:\n");
    display_matrix(matrix1, rows1, cols1);

    printf("Matrix 2:\n");
    display_matrix(matrix2, rows2, cols2);

    matrix_multiply(matrix1, matrix2, result, rows1, cols1, cols2);

    printf("Resultant Matrix:\n");
    display_matrix(result, rows1, cols2);

    return 0;
}
