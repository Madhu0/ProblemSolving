/*For question refer to https://www.hackerrank.com/challenges/crush
 * */

#include<stdio.h>

void performOperationsOnArray(long long int *arr, int low, int high, int weight) {
	for(int i = low; i <= high; i++) {
		arr[i] += weight;
	}
}

int findMax(long long int *arr, int len) {
	int max = arr[0];
	for(int i = 1; i < len; i++) {
		if (max < arr[i]) {
			max = arr[i];
		}
	}
	return max;
}

int main(){
	int len, operations;
	scanf("%d %d", &len, &operations);
	long long int max = 0;
	int low_bound = 0, upper_bound = 0;
	for(int i = 0; i < operations; i++) {
		int low, high, weight;
		scanf("%d %d %d", &low, &high, &weight);
		if (low_bound == 0) {
			low_bound = low;
			upper_bound = high;
			max = weight;
		} else if (upper_bound < low || low_bound > high) {
			if (max < weight) {
				max = weight;
				low_bound = low;
				upper_bound = high;
			}
		} else {
			low_bound = low > low_bound ? low : low_bound;
			upper_bound = high < upper_bound ? high : upper_bound;
			max += weight;
		}
	}
	printf("%d\n", max);
	return 0;
}
