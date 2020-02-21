#include <stdio.h>
#define MAX_SIZE 1001

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
  int order_num;
  scanf("%d", &order_num);

  long long test_case[MAX_SIZE][2];
  long long tmp[MAX_SIZE];

  for(int i = 0; i < order_num; i++){
    scanf("%lld %lld", &test_case[i][0], &test_case[i][1]);
  }

  for(int i = 0; i < order_num; i++){
    tmp[i] = lcm(test_case[i][0], test_case[i][1]);
  }

  for(int i = 0; i < order_num; i++){
    printf("%lld\n", tmp[i]);
  }

	return 0;
}
