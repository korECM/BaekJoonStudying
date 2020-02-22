#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int main(){
  int num;
  scanf("%d", &num);

  int factorial = 1;

  for(int i = num; i > 0; i--){
    factorial = factorial * i;
  }

  printf("%d", factorial);

    return 0;
}
