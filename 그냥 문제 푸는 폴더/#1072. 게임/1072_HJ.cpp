#include <stdio.h>
#include <stdlib.h>

int main(){
    long long playNum, winNum, winRate, winRate_tmp = 0;

    scanf("%lld %lld", &playNum, &winNum);

    winRate = ((float)((float)winNum/(float)playNum))*100;
    winRate_tmp = winRate;
    // printf("%lld\n", winRate_tmp);

    long long count = 0;

    if(winRate == 100 || winRate == 99){
        count = -1;
    }
    else{
        while(winRate_tmp == winRate){
            // printf("%lld\n", count);
            count++;
            winRate = ((double)((double)(winNum + count)/(double)(playNum + count)))*100;
        }
        // printf("%lf\n", ((double)((double)(winNum + count)/(double)(playNum + count))));
        
    }

    printf("%lld", count);
}