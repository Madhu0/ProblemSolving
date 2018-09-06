#include <stdio.h>
#include <stdlib.h>

void scanMatrix(int **matrix, int rows, int cols) {
    int i,j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int **matrix, int rows, int cols) {
    int i,j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int **createMatrixInMemory(int rows, int cols) {
    int **matrix;
    matrix = (int **)malloc(sizeof(int *) * rows);
    for(int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(sizeof(int) * cols);
    }
    return matrix;
}

void multiplyTwoMatrices(int **matrix1, int rows1, int cols1, int **matrix2, int rows2, int cols2, int **result) {
    int i,j;
    for (i = 0; i < rows1; i++) {
        for (j = 0; j < cols2; j++) {
            int sum = 0;
            for (int k = 0; k < cols1; k++) {
                sum += matrix1[i][k] * matrix2[k][j];
            }
            result[i][j] = sum;
        }
    }
}

int main() {
    int testcases;
    scanf("%d", &testcases);
    while(testcases--) {
        int rows1, cols1, rows2, cols2;
        int **matrix1, **matrix2, **result;
        scanf("%d%d", &rows1, &cols1);
        matrix1 = createMatrixInMemory(rows1, cols1);
        scanMatrix(matrix1, rows1, cols1);
        scanf("%d%d", &rows2, &cols2);
        matrix2 = createMatrixInMemory(rows2, cols2);
        scanMatrix(matrix2, rows2, cols2);
        result = createMatrixInMemory(rows1, cols2);
        multiplyTwoMatrices(matrix1, rows1, cols1, matrix2, rows2, cols2, result);
        printMatrix(result, rows1, cols2);
    }
}