#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000002

int card[MAX_SIZE];

int main(){
    int card_num;
    scanf("%d", &card_num);

    for(int i = 1; i < card_num + 1; i++){
        card[i] = i;
    }

    int tmp = card_num;
    int tail = card_num;
    int pop = 1;

    while(tmp != 1){
        card[pop++] = 0;
        card[++tail] = card[pop];
        card[pop++] = 0;
        tmp--;
    }

    for(int i = 1; i < MAX_SIZE + 1; i++){
        if(card[i] != 0){
            printf("%d", card[i]);
            break;
        }
    }



    return 0;
}