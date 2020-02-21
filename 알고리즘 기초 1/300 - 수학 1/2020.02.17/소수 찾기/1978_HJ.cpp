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

  int get_num;
  int total = 0;

  for(int i = 0; i < order_num; i++){
    total++;
    scanf("%d", &get_num);
    if(get_num > 1){
      for(int i = 2; i < get_num; i++){
        if(gcd(i, get_num) != 1){
          total--;
          break;
        }
      }
    }else if(get_num == 1) total--;
  }

  printf("%d", total);

  return 0;
}
