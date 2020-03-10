#include <stdio.h>
#include <stdlib.h>

int main(){
    long long A, B, V;
    scanf("%lld %lld %lld", &A, &B, &V);

    long long result = (V - A)/(A - B) + 2;

    if(A == V){
      printf("1");
    }
    else if((V-A)%(A-B) == 0){
      printf("%lld", result - 1);
    }
    else{
      printf("%lld", result);
    }
    return 0;
}