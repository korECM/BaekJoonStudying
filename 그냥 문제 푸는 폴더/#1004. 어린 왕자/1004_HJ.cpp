#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const int max_num = 51;

int main(){
    int test_case = 0;
    int start_x, start_y, end_x, end_y = 0;
    int planet_x[max_num] = {0, };
    int planet_y[max_num] = {0, };
    int planet_r[max_num] = {0, };

    scanf("%d", &test_case);

    for(int i = 0; i < test_case; i++){
        int planet_num = 0;
        scanf("%d %d %d %d", &start_x, &start_y, &end_x, &end_y);
        scanf("%d", &planet_num);

        for(int j = 0; j < planet_num; j++){
            scanf("%d %d %d", &planet_x[j], &planet_y[j], &planet_r[j]);
        }

        int count = 0;

        for(int j = 0; j < planet_num; j++){
            if((start_x - planet_x[j])*(start_x - planet_x[j]) + (start_y - planet_y[j])*(start_y - planet_y[j]) < (planet_r[j]*planet_r[j])){
                if(!((end_x - planet_x[j])*(end_x - planet_x[j]) + (end_y - planet_y[j])*(end_y - planet_y[j]) < (planet_r[j]*planet_r[j]))){
                    count++;
                }
            }

            else if(!((start_x - planet_x[j])*(start_x - planet_x[j]) + (start_y - planet_y[j])*(start_y - planet_y[j]) < (planet_r[j]*planet_r[j]))){
                if(((end_x - planet_x[j])*(end_x - planet_x[j]) + (end_y - planet_y[j])*(end_y - planet_y[j]) < (planet_r[j]*planet_r[j]))){
                    count++;
                }
            }
        }

        printf("%d\n", count);
    }


    return 0;
}