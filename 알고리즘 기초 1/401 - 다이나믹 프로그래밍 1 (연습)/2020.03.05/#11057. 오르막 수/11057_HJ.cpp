#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1001

int main() {
    int length;
    scanf("%d", &length);

    int dp[MAX_SIZE][10];

    for(int i = 0; i < 10; i++){
        dp[1][i] = 1;
    }

    for(int i = 2; i < length + 1; i++){
        for(int j = 0; j < 10; j++){
            for(int k = 0; k < j + 1; k++){
                dp[i][j] = ((dp[i][j]%10007) + (dp[i - 1][k])%10007)%10007;
            }
        }
    }

    int result = 0;

    for(int i = 0; i < 10; i++){
        result += (dp[length][i])%10007;
    }

    printf("%d", result%10007);


    return 0;
}