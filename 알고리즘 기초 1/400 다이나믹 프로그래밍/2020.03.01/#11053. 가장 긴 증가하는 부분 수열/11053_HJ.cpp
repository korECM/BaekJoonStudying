#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1001

int main() {
    int case_num;
    scanf("%d", &case_num);

    int number[MAX_SIZE];
    int dp[MAX_SIZE];
    for(int i = 1; i < case_num + 1; i++){
        scanf("%d", number[i]);
    }

    dp[1] = 1;

    for(int i = 2; i < case_num + 1; i++){
        if(number[i] > number[i - 1]){
            dp[i] = dp[i - 1] + 1;
        } 
        else if()
    }
}