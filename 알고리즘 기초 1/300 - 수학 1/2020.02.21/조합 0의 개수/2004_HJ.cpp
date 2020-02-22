#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

long long zeronum = 0;

long long fact(long long n){
    long long result = 1;
    long long tmp = 1;
    tmp = n;
    if(n == 0 || n == 1){
        return 1;
    }
    else{
        while(tmp % 10 == 0){
            tmp = tmp / 10;
            zeronum--;
        }
        result = tmp * fact(n - 1);
        while(result % 10 == 0){
            result = result / 10;
            zeronum--;
        }
        result = result % 1000;
        return result;
    }
}

int main(){
  long long start, end;
  scanf("%lld %lld", &start, &end);

  long long final = 1;
  long long tmp2 = 1;

  if(end == 0){
      zeronum = 0;
  }
  else{
      for(long long i = start; i > start - end; i--){
        tmp2 = i;
        while(tmp2 % 10 == 0){
          tmp2 = tmp2 / 10;
          zeronum++;
        }
        final = final * tmp2;
        while(final % 10 == 0){
          final = final / 10;
          zeronum++;
        }
        final = final % 1000;
      }
      long long play = 1;
      play = fact(end);
  }

  printf("%lld", zeronum);

    return 0;
}
