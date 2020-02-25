#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 101

int count = 0;
int coin[MAX_SIZE];
int coin_num, value;

void check(int num);

int main(){
    for(int i = 0; i < MAX_SIZE; i++){
      coin[i] = 100001;
    }

  scanf("%d %d", &coin_num, &value);

  for(int i = 0; i < coin_num; i++){
    scanf("%d", &coin[i]);
  }

  int temp = 0;

  for(int i = 0; i < coin_num - 1; i++){     //내림차순 정렬
        for(int j = 0; j < coin_num - 1 - i; j++){
            if(coin[j] < coin[j + 1]){
                temp        = coin[j];
                coin[j]     = coin[j + 1];
                coin[j + 1] = temp;
            }
        }
    }

  check(value);

  printf("%d", count);

  return 0;
}

void check(int num){
  count++;
  int i = 0;
  while(coin[i] >= num){
    i++;
  }
  if(coin[i] == num) count++;
  if(i == coin_num - 1){
    return;
  }else{
    check(coin[i]);
    check(num - coin[i]);
  }
}
