#include <stdio.h>
#include <stdlib.h>

int main(){
    int dp[21][21][21] = {{{1, }, }, };
    
    for(int i = 0; i < 21; i++){
        for(int j = 0; j < 21; j++){
            for(int k = 0; k < 21; k++){
                dp[i][j][k] = 1;
            }
        }
    }

    for(int i = 0; i < 21; i++){
        for(int j = 0; j < 21; j++){
            for(int k = 0; k < 21; k++){
                if(i <= 0 || j <= 0 || k <= 0){
                    dp[i][j][k] = 1;
                }
                else if(i < j && j < k){
                    dp[i][j][k] = dp[i][j][k-1] + dp[i][j-1][k-1] - dp[i][j-1][k];
                }
                else{
                    dp[i][j][k] = dp[i-1][j][k] + dp[i-1][j-1][k] + dp[i-1][j][k-1] - dp[i-1][j-1][k-1];
                }
                
                if(i <= 1){
                    // printf("dp[%d][%d][%d] = %d\n", i, j, k, dp[i][j][k]);
                }
            }
        }
    }

    while(1){
        int a_, b_, c_;
        scanf("%d %d %d", &a_, &b_, &c_);

        if(a_ == -1 && b_ == -1 && c_ == -1){
            break;
        }

        if(a_ <= 0 || b_ <= 0 || c_ <= 0){
            printf("w(%d, %d, %d) = %d\n", a_, b_, c_, 1);
        }
        else if(a_ > 20 || b_ > 20 || c_ > 20){
            printf("w(%d, %d, %d) = %d\n", a_, b_, c_, dp[20][20][20]);
        }
        else{
            printf("w(%d, %d, %d) = %d\n", a_, b_, c_, dp[a_][b_][c_]);
        }
    }

    return 0;
}