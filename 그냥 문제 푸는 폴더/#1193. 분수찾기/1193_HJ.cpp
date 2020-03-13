#include <stdio.h>
#include <stdlib.h>

int main(){
    int num;
    scanf("%d", &num);

    int tmp = num;
    int i = 1;
    while(tmp > 0){
        tmp = tmp - i;
        i++;
    }
    tmp = tmp + i - 1;

    if(i%2 == 1){
        if(tmp == 0){
            printf("%d/%d", tmp + 1, i - tmp -2);
        } 
        else{
            printf("%d/%d", tmp, i - tmp);
        }
    }
    else{
        if(tmp == 0){
            printf("%d/%d", i - tmp -2, tmp + 1);
        } 
        else{
            printf("%d/%d", i - tmp, tmp);
        }
    }

    return 0;
}