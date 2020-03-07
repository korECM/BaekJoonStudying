#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100001

int main(){
    int case_num;
    scanf("%d", &case_num);

    int result[MAX_SIZE];
    long long dp[MAX_SIZE][4];

    for(int i = 1; i < case_num + 1; i++){
        scanf("%d", &result[i]);
    }

    dp[1][1] = 1;

    dp[2][2] = 1;

    dp[3][1] = 1;
    dp[3][2] = 1;
    dp[3][3] = 1;

    dp[4][1] = 2;
    dp[4][3] = 1;
    
    for(int i = 5; i < MAX_SIZE; i++){
        dp[i][1] = (dp[i - 1][2] + dp[i - 1][3])%1000000009;
        dp[i][2] = (dp[i - 2][1] + dp[i - 2][3])%1000000009;
        dp[i][3] = (dp[i - 3][1] + dp[i - 3][2])%1000000009;
    }

    for(int i = 1; i < case_num + 1; i++){
        printf("%lld\n", (dp[result[i]][1] + dp[result[i]][2] + dp[result[i]][3])%1000000009);
    }


    return 0;
}