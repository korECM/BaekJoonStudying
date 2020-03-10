#include <stdio.h>
#include <stdlib.h>

int main(){
    long long A, B, C;
    scanf("%lld %lld %lld", &A, &B, &C);

    long long cost, revenue = 0;
    cost = A;
    int trynum = 1;
    int result = 0;

    if(B >= C){
      printf("-1");
      trynum = 0;
    }
    else{
      result = A/(C - B) + 1;
      printf("%d", result);
    }
    

    return 0;
}