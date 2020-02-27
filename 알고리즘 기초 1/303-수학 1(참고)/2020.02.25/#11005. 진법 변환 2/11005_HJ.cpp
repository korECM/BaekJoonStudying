#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 26

void print(long long a, int b){//숫자 a를 b진수로
  int tmp;
  tmp = a%b;
  if(a/b == 0){
    if(a >= 10 && a <= 35){
      printf("%c", 'A'- 10 + a);
    }else{
      printf("%d", a);
    }
  }else{
    print(a/b, b);
    if(tmp >= 10 && tmp <= 35){
      printf("%c", 'A'- 10 + tmp);
    }else{
      printf("%d", tmp);
    }
  }
}

int main(){
  long long dec = 0;
  int num;

  scanf("%lld %d", &dec, &num);

  print(dec, num);

  return 0;
}
