#include <stdio.h>

long int findHCF(long int a, long int b) {
    if (b == 0) {
        return a;
    } else {
        return findHCF(b, a % b);
    }
}

long long int findLCM(long int a, long int b, long int hcf) {
    return (a*b) / hcf;
}

int main() {
    int testcases;
    scanf("%d", &testcases);
    while(testcases--) {
        long int a, b;
        scanf("%ld%ld", &a, &b);
        long int hcf = a > b ? findHCF(a, b) : findHCF(b, a);
        printf("%lld %ld\n", findLCM(a, b, hcf), hcf);
    }
    return 0;
}