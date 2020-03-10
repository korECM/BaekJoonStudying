#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20000002

int card_count[MAX_SIZE];
int card_list[500001];

int main(){
  int case_num;
  scanf("%d", &case_num);

  for(int i = 0; i < case_num; i++){
    scanf("%d", &card_list[i]);
    if(card_list[i] < 0){
      card_count[(-1)*(card_list[i]) + 10000000]++;
    }else{
      card_count[card_list[i]]++;
    }
  }

  int count_case;
  scanf("%d", &count_case);

  int tmp;
  for(int i = 0; i < count_case; i++){
    scanf("%d", &tmp);
    if(tmp < 0){
      printf("%d ", card_count[(-1)*tmp + 10000000]);
    } 
    else {
      printf("%d ", card_count[tmp]);
    }
  }

  return 0;
}