#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 500000

int main(){
  int binary;
  scanf("%d", &binary);

  int tmp;
  int size = 0;
  int oct[MAX_SIZE];

  while(binary != 0){
    tmp = binary % 1000;
    if(tmp/100 == 1){
      oct[size] = oct[size] + 4;
    }
    tmp = tmp % 100;
    if(tmp/10 == 1){
      oct[size] = oct[size] + 2;
    }
    tmp = tmp % 10;
    if(tmp == 1){
      oct[size] = oct[size] + 1;
    }
    binary = binary / 1000;
    size++;
  }

  for(int i = size - 1; i > -1; i--){
    printf("%d", oct[i]);
  }

  return 0;
}
