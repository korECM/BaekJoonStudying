#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1001

int main() {
    int cardNum;
    scanf("%d", &cardNum);

    int cardPrice[MAX_SIZE];

    for(int i = 1 ; i < cardNum + 1; i++){
        scanf("%d", &cardPrice[i]);
    }

    int tmp = 1;
    int buyingCard = 0;
    long long payMoney = 0;

    while(buyingCard != cardNum){
        tmp = 1;
        for(int i = 2; i < cardNum + 1; i++){
            if((cardNum - buyingCard >= i) && (((double)cardPrice[i] / (double)i) < ((double)cardPrice[tmp] / (double)(tmp)))){
                tmp = i;
            }else if(cardNum - buyingCard < i){
                break;
            }
        }
        payMoney = payMoney + cardPrice[tmp];
        buyingCard = buyingCard + tmp;
    }

    printf("%lld", payMoney);

    return 0;
}