#include <stdio.h>
#include <stdlib.h>

void swapRows(int **matrix, int row1, int row2) {
    int *temp;
    temp = matrix[row1];
    matrix[row1] = matrix[row2];
    matrix[row2] = temp;
}

void swapElementsOfDiagonal(int **matrix, int rows, int columns) {
    int i,j;
    for (i = 1; i < rows; i++) {
        for (j = 0; j < i; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}

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

void rotateMatrix(int **matrix, int size) {
    int i, n = size - 1;
    for(i = 0; i < size/2; i++) {
        swapRows(matrix, i, n-i);
    }
//    printMatrix(matrix, size, size);
    swapElementsOfDiagonal(matrix, size, size);
    printMatrix(matrix, size, size);
}

int main() {
    int testcases, testCaseNo = 0;
    scanf("%d", &testcases);
    while(testcases--) {
        int **matrix, size, i, j;
        scanf("%d", &size);
        matrix = (int **)malloc(sizeof(int *)*size);
        for (i = 0; i < size; i++) {
            matrix[i] = (int *)malloc(sizeof(int)*size);
        }
        scanMatrix(matrix, size, size);
//        printMatrix(matrix, size, size);
        printf("Test Case #%d:\n", testCaseNo+1);
        rotateMatrix(matrix, size);
        testCaseNo++;
    }
}