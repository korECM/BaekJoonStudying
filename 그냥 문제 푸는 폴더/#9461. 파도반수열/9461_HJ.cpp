#include <stdio.h>
#include <stdlib.h>

int main(){
    long long dp[101] = {0, };

    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 2;

    for(int i = 6; i < 101; i++){
        dp[i] = dp[i-1] + dp[i-5];
    }

    int test_case = 0;
    scanf("%d", &test_case);

    for(int i = 0; i < test_case; i++){
        int tmp = 0;
        scanf("%d", &tmp);
        printf("%lld\n", dp[tmp]);
    }

    return 0;
}