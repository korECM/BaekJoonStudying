#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#define MAX_SIZE 100001

int zeronum = 0;

long long max_value(long long a, long long b){
  if(a < b) return b;
  else return a;
}
long long min_val(long long a, long long b){
  if(a > b) return b;
  else return a;
}

long long gcd(long long a, long long b){
	while(b!=0){
		int r = a%b;
		a= b;
		b= r;
	}
	return a;
}

int main(){
  long long young_num, me_pos;
  scanf("%lld %lld", &young_num, &me_pos);

  long long tmp_value[MAX_SIZE];
  long long tmp;
  long long greatest_value = 0;

  for(int i = 0; i < young_num; i++){
    scanf("%lld", &tmp);
    tmp_value[i] = abs(tmp - me_pos);
  }

  long long tmp2;
  long long min_value = 1000000001;

  if(young_num == 1){
    min_value = abs(me_pos - tmp_value[0]);
  }
  else{
    for(int i = 0; i < young_num - 1; i++){
      //tmp2 = gcd(tmp_value[i], tmp_value[i + 1]);
      min_value = min_val(min_value, tmp_value[i + 1] - tmp_value[i]);
    }
    for(int i = 0; i < young_num; i++){
      min_value = min_val(min_value, abs(tmp_value[i] - me_pos));
    }
  }

  printf("%lld", min_value);

  return 0;
}
