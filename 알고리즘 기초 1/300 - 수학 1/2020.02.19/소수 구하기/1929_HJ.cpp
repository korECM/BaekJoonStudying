#include <stdio.h>
#define MAX_SIZE 1000001

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
  int start_num, end_num;
  scanf("%d %d", &start_num, &end_num);
  printf("%d %d\n", start_num, end_num);

  int total = -1;
  int prime[MAX_SIZE];
  for(int i = start_num; i < end_num + 1; i++){
    total++;
    prime[total] = i;
    //printf("%d\n", prime[total]);
    if(i > 1){
      for(int j = 2; j < i; j++){
        if(gcd(j, i) != 1){
          prime[total] = 0;
          total--;
          break;
        }
      }
    }else if(i == 1) prime[total] = 0; total--;
  }

  for(int i = 0; i < MAX_SIZE; i++){
    if(prime[i] > 0){
      printf("%d\n", prime[i]);
    }
    else{
      break;
    }
  }

  return 0;
}
