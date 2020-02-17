#include <stdio.h>
#include <stdlib.h> //abs함수를 위한 헤더파일

#define MAX_CITY_SIZE 51
#define MAX_CHICKEN_NUM 14
#define MAX_DISTANCE 200000

int minnum(int a, int b){
    if(a>b) return b;
    else return a;
}

int chicken_distance(int a, int b, int citySize, int pos[MAX_CITY_SIZE][MAX_CITY_SIZE]){//치킨집의 좌표를 인자로 받아 치킨거리를 구함.
    int result = 0;
    
    for(int i = 1; i < citySize + 1; i++){
        for(int j = 1; j < citySize + 1; j++){
            if(pos[i][j] == 1){ //순회중 일반집을 만나면 거리 구하기.
                result = result + abs(i - a) + abs(j - b);
            }
        }
    }
    return result;
}

int chicken_distance_from_home(int a, int b, int citySize, int pos[MAX_CITY_SIZE][MAX_CITY_SIZE]){//치킨집의 좌표를 인자로 받아 치킨거리를 구함.
    int result = 2500;
    
    for(int i = 1; i < citySize + 1; i++){
        for(int j = 1; j < citySize + 1; j++){
            if(pos[i][j] == 2){ //순회중 치킨집을 만나면 거리 구하기.
                result = minnum(result, abs(i - a) + abs(j - b));   //최솟값 넣기
            }
        }
    }
    return result;
}

int main(){
    int city_size = 0;
    int max_chicken = 0;
    int position[MAX_CITY_SIZE][MAX_CITY_SIZE] = {0};
    int chicken_distance_array[MAX_CHICKEN_NUM][3] = {{MAX_DISTANCE, 0, 0}};    //{치킨거리, y좌표, x좌표}
    
    scanf("%d %d", &city_size, &max_chicken);
    
    for(int i = 1; i < city_size + 1; i++){
        for(int j = 1; j < city_size + 1; j++){
            scanf("%d", &position[i][j]);
        }
    }
    
    int chicken_order = 1;
    
    for(int i = 1; i < city_size + 1; i++){
        for(int j = 1; j < city_size + 1; j++){
            if(position[i][j] == 2){    //치킨집일 떄
                chicken_distance_array[chicken_order][0] = chicken_distance(i, j, city_size, position);    //각 치킨집의 치킨거리를 순서대로 배열에 대입                
                chicken_distance_array[chicken_order][1] = i;   //좌표도 저장
                chicken_distance_array[chicken_order][2] = j;
                chicken_order++;
            }
        }
    }
    
    //버블정렬로 배열에 있는 정수값 오름차순 정렬하기
    int temp[3] = {MAX_DISTANCE, 0, 0};
    
    for(int i = 1 ; i < chicken_order + 1 ; i ++) {
        for(int j = 1 ; j < chicken_order - i; j ++) {
            if(chicken_distance_array[j][0]>chicken_distance_array[j+1][0]) {
                for(int t = 0; t < 3; t++){
                    temp[t] = chicken_distance_array[j][t];
                    chicken_distance_array[j][t] = chicken_distance_array[j+1][t];
                    chicken_distance_array[j+1][t] = temp[t];
                }
            }
        }
    }
    
    
    //chicken_distance_array에 있는 값 중 max_chicken까지의 치킨집만 살리고 나머지는 0으로 바꿔주기.
    for(int i = max_chicken + 1; i < MAX_CHICKEN_NUM; i++){
        position[chicken_distance_array[i][1]][chicken_distance_array[i][2]] = 0;
    }
    
    //도시의 치킨거리의 최솟값 계산하기
    int total_distance = 0;
    
    for(int i = 1; i < city_size + 1; i++){
        for(int j = 1; j < city_size + 1; j++){
            if(position[i][j] == 1){    //일반집일 떄
                total_distance = total_distance + chicken_distance_from_home(i, j, city_size, position);    //각 치킨집의 치킨거리를 순서대로 배열에 대입                
               // printf("%d  ", chicken_distance_from_home(i, j, city_size, position));
            }
        }
    }
    
    printf("%d", total_distance);
    
    
    return 0;
}
