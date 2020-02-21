#include <stdio.h>
#define MAX_SIZE 10001

long long gcd(long long a, long long b){
	while(b!=0){
		int r = a%b;
		a= b;
		b= r;
	}
	return a;
}

long long lcm(long long a, long long b){
    return a * b / gcd(a,b);
}

int main(){

	int a, b;

	scanf("%d %d", &a, &b);

	printf("%lld\n%lld", gcd(a, b), lcm(a, b));
	return 0;
}
