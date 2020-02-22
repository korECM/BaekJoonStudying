#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#define MAX_SIZE 101

int zeronum = 0;

long long gcd(long long a, long long b){
	while(b!=0){
		int r = a%b;
		a= b;
		b= r;
	}
	return a;
}

int main(){
  int test_case;
  scanf("%d", &test_case);

  int test_num[MAX_SIZE];
  long long sum;
  int get_num;

  while(test_case--){
    sum = 0;
    scanf("%d", &get_num);

    for(int i = 0; i < get_num; i++){
      scanf("%d", &test_num[i]);
    }

    for(int i = 0; i < get_num - 1; i++){
      for(int j = i + 1; j < get_num; j++){
        sum = sum + gcd(test_num[i], test_num[j]);
      }
    }

    printf("%lld\n", sum);
  }

  return 0;
}
