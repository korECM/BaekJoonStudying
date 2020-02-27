#include <stdio.h>
#include <stdlib.h>

void print(int a){
  if(a == 1) return;
  for(int i = 2; i < a + 1; i++){
    if(a % i == 0){
      printf("%d\n", i);
      print(a/i);
      break;
    }
  }
}

int main(){
  int num;
  scanf("%d", &num);

  print(num);

  return 0;
}
