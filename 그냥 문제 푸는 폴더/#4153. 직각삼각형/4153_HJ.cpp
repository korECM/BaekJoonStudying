#include <stdio.h>
#include <stdlib.h>

void check_tri(int a, int b,int c){
    if(a > b && a > c){
        if(a*a == b*b + c*c){
            printf("right\n");
        }
        else{
            printf("wrong\n");
        }
    }
    else if(b > a && b > c){
        if(b*b == a*a + c*c){
            printf("right\n");
        }
        else{
            printf("wrong\n");
        }
    }
    else if(c > a && c > b){
        if(c*c == a*a + b*b){
            printf("right\n");
        }
        else{
            printf("wrong\n");
        }
    }
    else{
        printf("wrong\n");
    }
}

int main(){
    int num[100001][3];
    int trynum = 0;

    for(int i = 0; i < 100001; i++){
      scanf("%d %d %d", &num[i][0], &num[i][1], &num[i][2]);
      if(num[i][0] == 0){
        break;
      }
      trynum++;
    }

    for(int i = 0; i < trynum; i++){
      check_tri(num[i][0], num[i][1], num[i][2]);
    }

    return 0;
}