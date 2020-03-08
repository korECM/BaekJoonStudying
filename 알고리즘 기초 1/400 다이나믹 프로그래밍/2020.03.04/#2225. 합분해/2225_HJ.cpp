#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 201

int main() {
    int n_value, k_value;
    scanf("%d %d", &n_value, &k_value);

    long long dp[MAX_SIZE][MAX_SIZE]={0};
    for(int n=0;n<=n_value;n++){
        dp[1][n]=1;
    }
    
    for(int k=2;k<=k_value;k++){
        for(int n=0;n<=n_value;n++){
            for(int l=0;l<=n;l++){
                dp[k][n]+=dp[k-1][l];
            }
            dp[k][n]%=1000000000;
        }
    }

    printf("%lld", dp[k_value][n_value]);

    return 0;
}