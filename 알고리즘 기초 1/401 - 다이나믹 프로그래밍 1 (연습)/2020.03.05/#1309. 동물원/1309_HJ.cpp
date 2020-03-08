#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100001

int main() {
    int line;
    scanf("%d", &line);

    int dp[MAX_SIZE][4];

    dp[1][0] = 1;
    dp[1][1] = 1;
    dp[1][2] = 1;
    dp[1][3] = dp[1][0] + dp[1][1] + dp[1][2];

    int mod = 9901;

    for(int i = 2; i < line + 1; i++){
        dp[i][0] = (dp[i - 1][1] + dp[i - 1][2])%mod;
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][2])%mod;
        dp[i][2] = dp[i - 1][3] %mod;
        dp[i][3] = (dp[i][0] + dp[i][1] + dp[i][2])%mod;
    }

    printf("%d", dp[line][3]);

    return 0;
}