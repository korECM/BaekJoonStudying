#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1001

int main(){
  int order_size;
  scanf("%d", &order_size);

  int num_order[MAX_SIZE];

  for(int i = 0; i < order_size; i++){
    scanf("%d", &num_order[i]);
  }

    int temp;

  for(int i = 0; i < order_size; i++){
    for(int j = 0; j < order_size - 1; j++){
      if(num_order[j] > num_order[j + 1]){
        temp = num_order[j];
        num_order[j] = num_order[j + 1];
        num_order[j + 1] = temp;
      }
    }
  }

  //for(int i = 0; i < order_size; i++){
//      printf("%d ", num_order[i]);
 // }

  //printf("\n");

  int min_sum = 0;

  for(int i = 0; i < order_size; i++){
    for(int j = i; j < order_size; j++){
      min_sum = min_sum + num_order[i];
    }
  }

  printf("%d", min_sum);

  return 0;
}
