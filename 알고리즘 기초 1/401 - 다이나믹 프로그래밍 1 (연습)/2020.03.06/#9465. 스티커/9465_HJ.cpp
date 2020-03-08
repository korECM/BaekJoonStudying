#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100001

int main(){
    int test_case;
    scanf("%d", &test_case);

    int value[MAX_SIZE][2];
    int dp[MAX_SIZE][2];

    int tmp;
    bool top = 0;

    for(int i = 0; i < test_case; i++){
        scanf("%d", &tmp);
        for(int j = 0; j < 2; j++){
            for(int k = 1; k < tmp + 1; k++){
                scanf("%d", &value[k][j]);
            }
        }

        if(value[1][0] > value[1][1]){
            dp[1][0] = value[1][0];
            dp[1][1] = top;
        } else {
            dp[1][0] = value[1][1];
            dp[1][1] = !top;
        }


        for(int j = 2; j < tmp + 1; j++){
            if((dp[j - 1][0] + value[j][!dp[j - 1][1]]) >= (dp[j - 2][0] + value[j][dp[j - 1][1]])){
                dp[j][0] = (dp[j - 1][0] + value[j][!(dp[j - 1][1])]);
                dp[j][1] = !dp[j - 1][1];
            } else {
                dp[j][0] = (dp[j - 2][0] + value[j][(dp[j - 1][1])]);
                dp[j][1] = dp[j - 1][1];
            }
        }

        printf("%d\n", dp[tmp][0]);
    }

    return 0;
}