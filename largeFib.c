#include<stdio.h>

int nthFibonacci(int n, long long int *arr) {
	if (n==0) {
		arr[0] = 1;
		arr[1] = 1;
		return 0;
	}
	int mod = 1000000007;
	nthFibonacci(n/2, arr);
	long long int a, b, c, temp;
	a = arr[0];
	b = arr[1];
	if (a < 0)
		a += mod;
	if (b < 0)
		b += mod;
	temp = (2*b - a);
	printf("a * temp %lld\n", a*temp);
	arr[0] = (a*temp)%mod;
	arr[1] = ((a*a)%mod + (b*b)%mod)%mod;
	c = arr[1] - arr[0];
	printf("arr[0] %lld arr[1] %lld \n", arr[0], arr[1]);
	if (n%2 == 0) {
		arr[1] = arr[0];
		arr[0] = c;
	}
	return 0;
}

int main() {
	int n;
	long long int res[2];
	scanf("%d", &n);
	while(n >= 0) {
		nthFibonacci(n, res);
		printf("%lld %lld\n", res[0], res[1]);
		scanf("%d", &n);
	}
	printf("%d %d %lld", -1%1000, -2%1000,(long long int)241320480389533567);
	return 1;
}
