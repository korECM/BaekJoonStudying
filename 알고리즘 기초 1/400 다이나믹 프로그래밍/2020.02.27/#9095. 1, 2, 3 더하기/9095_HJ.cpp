#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_TEST_CASE 11
#define MAXNUM 1000001

int maxValue(int a, int b){
    if(a > b) return a;
    else return b;
}

int main(){
    int caseNum[MAXNUM] = {0};
    int resultOrder[MAXNUM] = {0};
    int maxcase = 0;
    caseNum[1] = 1;
    caseNum[2] = 2;
    caseNum[3] = 4;

    int test_case_num = 0;
    scanf("%d", &test_case_num);
    for(int i = 0; i < test_case_num; i++){
        scanf("%d", &resultOrder[i]);
    }
    for(int i = 0; i < test_case_num; i++){
        maxcase = maxValue(maxcase, resultOrder[i]);
    }
    for(int i = 4 ; i <= maxcase ; i++){
        caseNum[i] = caseNum[i - 1] + caseNum[i - 2] + caseNum[i - 3];
    }

    for(int i = 0; i < test_case_num; i++){
        printf("%d\n", caseNum[resultOrder[i]]);
    }


    return 0;
}
