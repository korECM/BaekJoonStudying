#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100001

int max(int a, int b){
    if(a > b) return a;
    else return b;
}

int main() {
    int case_num;
    scanf("%d", &case_num);
    
    int positive = 0;
    int maximum = -1000;
    
    int number[MAX_SIZE];
    int dp[MAX_SIZE];   //자기 자신, dp2, dp3와 비교해서 최대값
    int dp2[MAX_SIZE];  //감소하는 순간이 와도 끊기엔 성급하니 일단 더해두는 공간
    int dp3[MAX_SIZE];  //dp2가 음수가 되어 끊어야하고 새로운 수열이 dp보다 값이 커질 경우를 대비한 공간

    for(int i = 1; i < case_num + 1; i++){
        scanf("%d", &number[i]);
        if(number[i] > 0){
            positive++;
        }
        maximum = max(maximum, number[i]);
    }

        dp[1] = number[1];
        dp2[1] = number[1];
        
   if (positive == 0){  //다 음수면
        dp[1] = maximum;
        dp2[1] = maximum;
    }
    
    //printf("1 :    dp[1] = %d,    dp2[1] = %d,    dp3[1] = %d\n", dp[1], dp2[1], dp3[1]);

    
    for(int i = 2; i < case_num + 1; i++){
        if(number[i] > 0 && (dp2[i - 1] == dp[i - 1]) && (dp[i - 1] > 0)){
            dp[i] = dp[i - 1] + number[i];
        } else {
            if(dp[i - 1] <= 0 && number[i] > 0){
                dp[i] = number[i];
            }else{
                 dp[i] = dp[i - 1];
            }
        }
        if(dp[i] < 0){
            dp2[i] = dp[i];
        }else{
            if(dp[i] > dp[i - 1]){
                dp2[i] = dp[i];
            }else{
                dp2[i] = dp2[i - 1] + number[i];
            }
        }
        
        if(dp2[i - 1] < 0 || dp3[i - 1] > dp2[i - 1]){
            dp3[i] = dp3[i - 1] + number[i]; 
        }
        
        if(dp3[i] > dp[i]){
            dp[i] = dp3[i];
            dp2[i] = dp[i];
            dp3[i] = 0;
        }
        if(dp2[i] > dp[i]){
            dp[i] = dp2[i];
            dp3[i] = 0;
        }
        //printf("%d :    dp[%d] = %d,    dp2[%d] = %d,    dp3[%d] = %d\n", i, i, dp[i], i, dp2[i], i, dp3[i]);
    }

    printf("%d", dp[case_num]);


    return 0;
}

//예외없는데에에에ㅠㅠㅠㅠㅠㅠ
// 시험해본 테스트 케이스

// 10
// 10 -4 3 1 5 6 -35 12 21 -1

// 6
// 6 -7 3 -1 5 2

// 5
// -3 -4 -7 -1 -8

// 6
// -1 -2 -7 5 3 7

// 5
// -1 -7 -8 -4 99

// 4
// 1 2 -2 4

// 1
// -900

// #include <stdio.h>
 
// int main(void){
 
//     int N;
//     int number[100010] = {};
//     int Dp[100010] = {};
//     int max;
//     scanf("%d", &N);
 
//     for (int i = 1; i <= N; i++)
//         scanf("%d", &number[i]);
 
//     for (int i = 1; i <= N; i++)
//     {
        
//         if (Dp[i - 1] + number[i] > number[i]){
//             Dp[i] = Dp[i - 1] + number[i];
//         }
//         else
//         {
//             Dp[i] = number[i];
//         }
    
//     }
//     max = Dp[1];
//     for (int i = 2; i <= N; i++)
//             if (max < Dp[i])
//                 max = Dp[i];
 
//     printf("%d\n", max);
// }