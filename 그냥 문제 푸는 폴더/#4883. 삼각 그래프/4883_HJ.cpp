#include <stdio.h>
#include <stdlib.h>

int most_min(int a, int b, int c){
    if(a > b){
        if(b > c){
            return c;
        }
        else return b;
    }
    else{
        if(a > c){
            return c;
        }
        else return a;
    }
}

int compare_min(int a, int b){
    if(a > b) return b;
    else return a;
}

int main(){
    int case_num = 0;
    
    int end = 0;
    
    int count = 1;
    
    while(1){
        long long dp[100002][3] = {{0,},};
        // int cost[100002][3] = {{0,},};
        
        
        scanf("%d", &case_num);
        if(case_num == 0){
            break;
        }

        for(int i = 0; i < case_num; i++){
            scanf("%lld %lld %lld", &dp[i][0], &dp[i][1], &dp[i][2]);
        }

        dp[1][0] = dp[1][0] + dp[0][1];
        dp[1][1] = most_min(dp[1][1] + dp[1][0], dp[0][1] + dp[0][2] + dp[1][1], dp[1][1] + dp[0][1]);
        dp[1][2] = most_min(dp[1][1] + dp[1][2], dp[1][2] + dp[0][1], dp[1][2] + dp[0][1] + dp[0][2]);
 
        for (int i = 2; i < case_num; i++) {
            dp[i][0] += most_min(dp[i-1][0], dp[i-1][1], dp[i-1][1]);
            dp[i][1] += most_min(compare_min(dp[i][0], dp[i-1][0]), dp[i-1][2], dp[i-1][1]);
            dp[i][2] += most_min(dp[i][1], dp[i-1][2], dp[i-1][1]);
        }

        printf("%d. %lld\n", count, dp[case_num - 1][1]);
        count++;
    }
    

    return 0;
}

// #include <stdio.h>
// #include <stdlib.h>

// int most_min(int a, int b, int c){
//     if(a > b){
//         if(b > c){
//             return c;
//         }
//         else return b;
//     }
//     else{
//         if(a > c){
//             return c;
//         }
//         else return a;
//     }
// }

// int main(){
//     int case_num = 0;
    
//     int end = 0;
    
//     int count = 1;
    
//     while(1){
//         long long dp[100002] = {0};
//         int cost[100002][3] = {{0,},};
        
        
//         scanf("%d", &case_num);
//         if(case_num == 0){
//             break;
//         }

//         for(int i = 0; i < case_num; i++){
//             scanf("%d %d %d", &cost[i][0], &cost[i][1], &cost[i][2]);
//         }

//         dp[1] = cost[0][1];
//         dp[2] = cost[0][1] + cost[1][1];
//         for(int i = 3; i < case_num + 1; i++){
//             dp[i] = most_min((dp[i-2] + most_min(cost[i-2][0], cost[i-2][1], cost[i-2][2]) + cost[i-1][1]), (dp[i-1] + cost[i-1][1]), (dp[i-1] - cost[i-2][1] + most_min(cost[i-2][0], cost[i-2][1], cost[i-2][2]) + cost[i-1][1]));
//         }

//         printf("%d. %lld\n", count, dp[case_num]);
//         count++;
//     }
    

//     return 0;
// }