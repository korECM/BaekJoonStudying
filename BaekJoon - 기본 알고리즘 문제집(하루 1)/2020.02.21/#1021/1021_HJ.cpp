#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 51

int main(){
  int queue_size, pop_num;
  int pop_element[MAX_SIZE];
  int element_left[MAX_SIZE];
  int element_right[MAX_SIZE];
  scanf("%d %d", &queue_size, &pop_num);

  int tmp = 0;
  for(int i = 0; i < pop_num; i++){
    scanf("%d", &tmp);
    element_left[tmp] = tmp;
    element_right[tmp] = queue_size - tmp + 1;
    pop_element[i] = tmp; //뺄 순서대로 넣은 배열
  }

  int total_move = 0;

  for(int i = 0; i < pop_num; i++){
    queue_size--;
    // for(int k = i; k < pop_num; k++){
    //     printf("%d's left : %d || %d's right : %d\n", pop_element[k], element_left[pop_element[k]], pop_element[k], element_right[pop_element[k]]);
    // }

    if(element_left[pop_element[i]] < element_right[pop_element[i]]){
      total_move = total_move + element_left[pop_element[i]] - 1;
      for(int j = i + 1; j < pop_num; j++){
        if(element_left[pop_element[j]] > element_left[pop_element[i]]){
          element_left[pop_element[j]] = element_left[pop_element[j]] - element_left[pop_element[i]];
          element_right[pop_element[j]] = element_right[pop_element[j]] + element_left[pop_element[i]] - 1;
        }
        else{
          element_right[pop_element[j]] = element_left[pop_element[i]] - element_left[pop_element[j]];
          element_left[pop_element[j]] = queue_size - element_right[pop_element[j]];
        }
      }
    }

    else{
      total_move = total_move + element_right[pop_element[i]] - 1;
      for(int j = i + 1; j < pop_num; j++){
        if(element_right[pop_element[j]] > element_right[pop_element[i]]){
          element_right[pop_element[j]] = element_right[pop_element[j]] - element_right[pop_element[i]];
          element_left[pop_element[j]] = element_left[pop_element[j]] + element_right[pop_element[i]] - 1;
        }
        else{
          element_left[pop_element[j]] = element_right[pop_element[i]] - element_right[pop_element[j]];
          element_right[pop_element[j]] = queue_size - element_left[pop_element[j]];
        }
      }
    }
    // printf("%d's total move : %d \n", pop_element[i], total_move);
  }

  printf("%d", total_move);
  return 0;
}
