#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000001

int main(){
  char binary[MAX_SIZE];
  scanf("%s", binary);

  char r_binary[MAX_SIZE];

  int tmp = 0;
  int size = 0;
  int oct[MAX_SIZE];

  for(int i = 1; i < strlen(binary) + 1; i++){
    r_binary[strlen(binary) - i] = binary[i - 1];
  }

  while(tmp < strlen(binary)){
      if(r_binary[tmp] == '1'){
          oct[size] = oct[size] + 1;
      }
      if(r_binary[++tmp] == '1'){
          oct[size] = oct[size] + 2;
      }
      if(r_binary[++tmp] == '1'){
          oct[size] = oct[size] + 4;
      }
      tmp++;
      size++;
  }

  for(int i = size - 1; i > -1; i--){
    printf("%d", oct[i]);
  }

  return 0;
}
