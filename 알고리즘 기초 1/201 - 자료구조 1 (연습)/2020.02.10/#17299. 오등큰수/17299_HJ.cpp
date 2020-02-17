#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100000

int bigger(int a, int b){
  if(a > b) return a;
  else return b;
}

int main(){
  int value_arr[MAX_STACK_SIZE] = {0};
  int F_arr[MAX_STACK_SIZE] = {0};
  int real_F[MAX_STACK_SIZE] = {0};
  int ngf[MAX_STACK_SIZE] = {0};
  int biggest_value = 0;
  int value = 0;
  int stack_size = 0;


  scanf("%d", &stack_size);

  for(int i = 1; i < stack_size + 1; i++){
    scanf("%d", &value_arr[i]);
    F_arr[value_arr[i]]++;
  }

  for(int i = 1; i < stack_size + 1; i++){
    biggest_value = bigger(biggest_value, F_arr[i]);
  }

  for(int i = 1; i < stack_size + 1; i++){
      real_F[i] = F_arr[value_arr[i]];
  }

  for(int i = 1; i < stack_size + 1; i++){
    if(real_F[i] == biggest_value){
      ngf[i] = -1;
    }
  }

  for(int i = 1; i < stack_size + 1; i++){
    if(ngf[i] == 0){  //할당된 애가 아니면
      for(int j = i + 1; j < stack_size + 1; j++){
        if(ngf[j] == -1){
            ngf[i] = value_arr[j];
            break;
        }
        else if(real_F[i] < real_F[j]){
            ngf[i] = value_arr[j];
            break;
        }

      }
    }
  }

  for(int i = 1; i < stack_size + 1; i++){
    printf("%d ", ngf[i]);
  }

  return 0;
}
