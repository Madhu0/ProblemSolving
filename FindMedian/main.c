#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int quickPartition(int *arr, int low, int high) {
    int pivot = low, i = low + 1, j = high;
    while(1) {
        while(i <= high && arr[i] < arr[pivot])
            i++;
        while(j >= low && arr[j] > arr[pivot])
            j--;
        if (i >= j) {
            swap(&arr[pivot], &arr[j]);
            return j;
        }
        swap(&arr[i], &arr[j]);
        i++;
        j--;
    }
}

void quickSort(int *arr, int low, int high) {
    if(low < high) {
        int pivot = quickPartition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}


int main() {
    int testcases;
    scanf("%d", &testcases);
    while(testcases--) {
        int size;
        scanf("%d", &size);
        int arr[size];
        for(int i = 0; i < size; i++) {
            scanf("%d", &arr[i]);
        }
        quickSort(arr, 0, size - 1);
        if (size % 2 == 0) {
            int mid = size / 2 - 1;
            int res = (int)(arr[mid] + arr[mid + 1]) / 2;
            printf("%d\n", res);
        } else {
            printf("%d\n", arr[size / 2]);
        }
    }
    return 0;
}