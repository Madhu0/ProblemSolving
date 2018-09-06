/**
 * Problem Link: https://www.interviewbit.com/problems/maximum-consecutive-gap/
 * Author: Madhu
 * Date: Sep 7, 2018
 i*/
int maximumGap(const int* A, int n1) {
    if (n1 < 2) {
        return 0;
    }
    int min, max;
    int i, bSize, bNo;
    min = A[0], max = A[0];
    for(i = 1; i < n1; i++) {
        if (min >= A[i]) {
            min = A[i];
        }
        if (max <= A[i]) {
            max = A[i];
        }
    }
    if (min == max) {
        return 0;
    }
    bSize = ceil((double)(max - min) / (n1 - 1));
    bNo = floor((double)(max - min) / bSize) + 1;
    // printf("----%d %d----\n", bSize, bNo);
    int buckets[bNo][2];
    memset((void *)buckets, -1, sizeof(buckets));
    for(i = 0; i < n1; i++) {
        int pos;
        pos = (A[i] - min) / bSize;
        // printf("pos of %d is %d\n", A[i], pos);
        if (buckets[pos][0] == -1) 
            buckets[pos][0] = A[i];
        if (buckets[pos][1] == -1) 
            buckets[pos][1] = A[i];
        if (buckets[pos][0] > A[i])
            buckets[pos][0] = A[i];
        if (buckets[pos][1] < A[i]) 
            buckets[pos][1] = A[i];
    }
    for( i = 0; i < bNo; i++) {
        // printf("i %d => %d %d\n", i, buckets[i][0], buckets[i][1]);
    }
    int maxDef = bSize;
    for(i = 0; i < bNo - 1; i++) {
        if (buckets[i][1] != -1) {
            int j = i + 1;
            while(j < bNo && buckets[j][0] == -1) {
                j++;
            }
            if (j < bNo) {
                int temp = buckets[j][0] - buckets[i][1];
                if (maxDef < temp) {
                    maxDef = temp;
                }
            }
        }
    }
    return maxDef;
}

