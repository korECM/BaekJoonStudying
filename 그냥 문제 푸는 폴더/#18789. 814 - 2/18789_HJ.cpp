#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int num[4][4];
int tmp = 1;
int done;

void give_value(int a, int b){
    if(a < 0 || b < 0 || a > 13 || b > 13){
        return;
    }else{
        for(int i = -1; i < 2; i++){
            for(int j = -1; j < 2; j++){
                if(num[a + i][b + j] == -1){
                    while(1){
                        tmp = rand()%10;
                        done = 1;
                        for(int m = -1; m < 2; m++){
                            for(int n = -1; n < 2; n++){
                                if(!(m == 0 && n == 0)){
                                    if(tmp == num[a + m][b + n]){
                                        done = 0;
                                    }
                                }
                            }
                        }
                        if(done == 1){
                            num[a + i][b + j] = tmp;
                            break;
                        }else{

                        }
                    }
                }
            }
        }
        // give_value(a - 1, b - 1);
        // give_value(a - 1, b + 1);
        // give_value(a + 1, b - 1);
        // give_value(a + 1, b + 1);
    }    
}

int main(){
    
    srand((unsigned int)time(NULL));
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 14; j++){
            // num[i][j] = rand()%10;
            num[i][j] = -1;
        }
    }

    // num[4][7] = 1;
    num[0][0] = 1;
    // give_value(4, 7);

    for(int i = 0; i < 8; i++){
      for(int j = 0; j < 14; j++){
        give_value(i, j);
      }
    }
    

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 14; j++){
            printf("%d", num[i][j]);
        }
        printf("\n");
    }

    return 0;
}