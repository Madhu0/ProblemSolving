#include <stdio.h>
#include <stdlib.h>

#define LEFT_CHILD(i) (2*i + 1)
#define RIGHT_CHILD(i) (2*i + 2)

void swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

void printArray(int *A, int len) {
    for(int i = 0; i < len; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int* createArray(int len) {
    return (int *)malloc(sizeof(int) * len);
}

int* scanArray(int len) {
    int *arr = createArray(len);
    for(int i = 0; i < len; i++) {
        scanf("%d", &arr[i]);
    }
    return arr;
}

void percolateDown(int *A, int root, int len) {
//    printf("In percolateDown");
    if (root < len) {
        int leftChildIndex = LEFT_CHILD(root);
        int rightChildIndex = RIGHT_CHILD(root);

        int maxIndex = root;
        if (leftChildIndex < len && A[maxIndex] <= A[leftChildIndex]) {
            maxIndex = leftChildIndex;
        }
        if (rightChildIndex < len && A[maxIndex] <= A[rightChildIndex]) {
            maxIndex = rightChildIndex;
        }
        if (maxIndex != root) {
            swap(&A[root], &A[maxIndex]);
            percolateDown(A, maxIndex, len);
        }
    }
}

void buildHeap(int *A, int len) {
//    printf("In buildHeap");
    int lastNonLeafNode = (len - 1) / 2;
    for(int i = lastNonLeafNode; i >= 0; i--) {
        percolateDown(A, i, len);
    }
}

void heapSort(int *A, int len) {
//    printf("In Heapsort");
    buildHeap(A, len);
//    printArray(A, len);
    for(int i = 1; i < len; i++) {
        swap(&A[0], &A[len - i]);
        percolateDown(A, 0, len-i);
    }
}

int main() {
    int len;
    scanf("%d", &len);
    int *arr = scanArray(len);
    heapSort(arr, len);
    printArray(arr, len);
    return 0;
}