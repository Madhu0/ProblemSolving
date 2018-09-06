#include <stdio.h>

int main() {
    int n;
    printf("Enter n\n");
    scanf("%d", &n);
    long long int r = 0;
    for(int i = 1; i <= n - 1; i++) {
        for(int j = i + 1; j <= n; j++) {
            for (int k = 1; k <= j; k++) {
                r++;
            }
        }
    }
    printf("R value: %d", r);
    return 1;
}