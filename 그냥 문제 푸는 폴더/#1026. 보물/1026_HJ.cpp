#include <stdio.h>
#include <stdlib.h>

int main(){
    int a_array[51] = {0,};
    int b_array[51] = {0,};

    int n = 0;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &a_array[i]);
    }

    for(int i = 0; i < n; i++){
        scanf("%d", &b_array[i]);
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(a_array[i] > a_array[j]){
                int tmp = a_array[i];
                a_array[i] = a_array[j];
                a_array[j] = tmp;
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(b_array[i] < b_array[j]){
                int tmp = b_array[i];
                b_array[i] = b_array[j];
                b_array[j] = tmp;
            }
        }
    }

    int result = 0;

    for(int i = 0; i < n; i++){
        result = result + a_array[i]*b_array[i];
    }

    printf("%d", result);


    return 0;
}