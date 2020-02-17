#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 1000001

int bigger(int a, int b){
  if(a > b) return a;
  else return b;
}

int main(){
  int value_arr[MAX_STACK_SIZE] = {0};
  int nge[MAX_STACK_SIZE] = {0};
  int biggest_value = 0;
  int value = 0;
  int stack_size = 0;

  scanf("%d", &stack_size);

  for(int i = 1; i < stack_size + 1; i++){
    scanf("%d", &value_arr[i]);
  }

  for(int i = 1; i < stack_size + 1; i++){
    biggest_value = bigger(biggest_value, value_arr[i]);
  }

  for(int i = 1; i < stack_size + 1; i++){
    if(value_arr[i] == biggest_value){
      nge[i] = -1;
    }else if(value_arr[i + 1] == 0){
        nge[i] = -1;
    }
  }

  for(int i = 1; i < stack_size + 1; i++){
    if(nge[i] == 0){  //할당된 애가 아니면
      for(int j = i + 1; j < stack_size + 1; j++){
        if(nge[j] == -1){
            nge[i] = value_arr[j];
            break;
        }
        else if(value_arr[i] < value_arr[j]){
            nge[i] = value_arr[j];
            break;
        }
      }
    }
  }

  for(int i = 1; i < stack_size + 1; i++){
    printf("%d ", nge[i]);
  }

  return 0;
}
