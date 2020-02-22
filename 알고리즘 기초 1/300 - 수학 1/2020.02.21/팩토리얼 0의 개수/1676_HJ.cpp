#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int zeronum = 0;

int fact(int n){
    int result = 1;
    if(n == 0 || n == 1){
        return 1;
    }
    else{
        result = n * fact(n - 1);
        while(result % 10 == 0){
            result = result / 10;
            zeronum++;
        }
        result = result%1000;
        return result;
    }
}

int main(){
  int num;
  scanf("%d", &num);
    int play;
    play = fact(num);


  printf("%d", zeronum);

    return 0;
}


/*
int main(){
  int num;
  scanf("%d", &num);

  int factorial = 1;
  int zeronum = 0;

  for(int i = num; i > 0; i--){
    factorial = factorial * i;
    while(factorial % 10 == 0){
      factorial = factorial / 10;
      zeronum++;
    }
  }

  printf("%d", zeronum);

    return 0;
}
*/
