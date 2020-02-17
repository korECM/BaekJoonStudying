#include <stdio.h>

#define HOUSE_NUM_MAX 1001
#define COST_MAX 1001

int nowColor = -1;
int previousColor = 0;

int minimumValue(int a, int b){
    if(a > b) return b;
    else return a;
}

int main(){
    int color_cost[HOUSE_NUM_MAX][3] = {COST_MAX};
    int numOfHouse = 0;
    int arr[3] = {0};
    int tmp[3];
    int minimumSum = 0;

    scanf("%d", &numOfHouse);

    for(int i = 0; i < numOfHouse; i++){
        scanf("%d %d %d", &color_cost[i][0], &color_cost[i][1], &color_cost[i][2]);
    }

    for(int i = 0; i < numOfHouse; i++){
        tmp[0] = arr[0];
        tmp[1] = arr[1];
        tmp[2] = arr[2];

        arr[0] = color_cost[i][0] + minimumValue(tmp[1], tmp[2]);
        arr[1] = color_cost[i][1] + minimumValue(tmp[0], tmp[2]);
        arr[2] = color_cost[i][2] + minimumValue(tmp[0], tmp[1]);
    }
    minimumSum = minimumValue(minimumValue(arr[0], arr[1]), arr[2]);

    printf("%d", minimumSum);

    return 0;
}
