#include <stdio.h>
#include <stdlib.h>

int main(){
  int wannabe;
  scanf("%d", &wannabe);

  int trynum = 1;
  while(wannabe != 1){
      if(wannabe%2 == 1){
          trynum++;
      }
      wannabe = wannabe/2;
  }

  printf("%d", trynum);

  return 0;
}
