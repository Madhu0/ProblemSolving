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

void printRowOrColumn(int **matrix, int row, int column, int isRow, int shouldIncrement, int threshold) {
    for (int i = (isRow ? column : row); shouldIncrement ? i <= threshold : i >= threshold; shouldIncrement ? i++ : i--) {
        printf("%d ", isRow ? matrix[row][i] : matrix[i][column]);
    }
}

void printSpiralTraversal(int **matrix, int row, int col) {
    int rowEnd = row - 1, colEnd = col - 1, i = 0, j = 0;
    while(i < row && j < col) {
        printRowOrColumn(matrix, i, j, 1, 1, colEnd);
        printRowOrColumn(matrix, i + 1, colEnd, 0, 1, rowEnd);
        printRowOrColumn(matrix, rowEnd, colEnd - 1, 1, 0, j);
        printRowOrColumn(matrix, rowEnd - 1, j, 0, 0, i + 1);
        i++, j++;
        rowEnd--, colEnd--;
    }
}

int main() {
    int testcases;
    scanf("%d", &testcases);
    while(testcases--) {
        int size, **matrix;
        scanf("%d", &size);
        matrix = (int **)malloc(sizeof(int *) * size);
        for (int i = 0; i < size; i++) {
            matrix[i] = (int *)malloc(sizeof(int) * size);
        }
        scanMatrix(matrix, size, size);
        printSpiralTraversal(matrix, size, size);
        printf("\n");
    }
    return 0;
}