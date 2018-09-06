#include <stdio.h>

long long int findTrailingZeros(long long int number) {
    long long int count = 0;
    long long int temp = 5;
    while(temp <= number) {
        count += number / temp;
//        printf("%lld\n", count);
        temp *= 5;
    }
    return count;
}

int main() {
    int testcases;
    scanf("%d", &testcases);
    while(testcases--) {
        long long int num;
        scanf("%lld", &num);
        printf("%lld\n", findTrailingZeros(num));
    }
    return 0;
}