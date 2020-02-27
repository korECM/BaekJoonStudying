#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 26

void print(int a, int b){//숫자 a를 b진수로
  int tmp;
  tmp = a%b;
  if(a/b == 0){
    printf("%d ", a);
  }else{
    print(a/b, b);
    printf("%d ", tmp);
  }
}

int main(){
  int a_world, b_world;
  scanf("%d %d", &a_world, &b_world);

  int num;
  scanf("%d",&num);

  int origin[MAX_SIZE];
  long long dec = 0;

  for(int i = num - 1; i > -1; i--){
    scanf("%d", &origin[i]);
  }

  for(int i = 0; i < num; i++){
    dec = dec + origin[i]*pow(a_world, i);
  }

  print(dec, b_world);

  return 0;
}
