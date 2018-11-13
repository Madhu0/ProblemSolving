/*
 * Author: Madhusudhan Reddy K
 * ProblemLink: https://www.interviewbit.com/problems/rotate-matrix/
 * */
void replaceWithHorizontalImages(int **A, int rows, int cols) {
    int i, j;
    for(i = 0; i < rows / 2; i++) {
        int *temp = A[i];
        A[i] = A[rows - 1 - i];
        A[rows - i - 1] = temp;
    }
}

void replaceWithDiagonalImages(int **A, int rows, int cols) {
    int i,j;
    for(i = 0; i < rows; i++) {
        for(j = i; j < cols; j++) {
            int temp = A[i][j];
            A[i][j] = A[j][i];
            A[j][i] = temp;
        }
    }
}
 
void rotate(int** A, int n11, int n12) {
    replaceWithHorizontalImages(A, n11, n12);
    replaceWithDiagonalImages(A, n11, n12);
    // return 0;
}
