#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 100001

int min(int a, int b){
    if(a < b) return a;
    else return b;
}

int main(){
    int num;
    scanf("%d", &num);

    int dp[MAX_SIZE];

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    dp[4] = 1;
    
    int tmp, tmp2;
    int minval;

    for(int i = 5; i < num + 1; i++){
        minval = 1000;
        tmp = (int)sqrt(i);
        for(int j = tmp; j > 1; j--){
            minval = min(minval, dp[i - j*j]);
        }
        dp[i] = minval + 1;
        //printf("%d  ", i - (pow((double)((int)sqrt(i)), 2.0)));
        //printf("%d ", dp[i]);
    }

    printf("%d", dp[num]);

    return 0;
}