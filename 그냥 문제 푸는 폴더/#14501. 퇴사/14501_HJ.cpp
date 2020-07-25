#include <stdio.h>
#include <stdlib.h>

const int MAX = 17;

int max_(int a, int b){
    if(a > b) return a;
    else return b;
}

int main(){
    int n = 0;
    scanf("%d", &n);

    int time_[MAX] = {0, };
    int pay[MAX] = {0, };
    int dp[MAX] = {0, };

    for(int i = 1; i < n + 1; i++){
        scanf("%d %d", &time_[i], &pay[i]);
    }

    for(int i = 1; i <= n + 1; i++){
        for(int j = 1; j < i; j++){
            dp[i] = max_(dp[i], dp[j]);
        
            if(j + time_[j] == i){
                dp[i] = max_(dp[i], dp[j] + pay[j]);
            }        
        }
    }

    printf("%d", dp[n+1]);

    return 0;
}