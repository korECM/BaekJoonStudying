#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_SIZE 100

int main(){
  char order[MAX_SIZE];
  scanf("%s", order);

  int i = 0; //입력 자릿수

  while((order[i] >= 'A' && order[i] <= 'Z') || (order[i] >= '0' && order[i] <= '9')){
    i++;
  }

  int num = 0;
  scanf("%d", &num);

//   printf("%d\n", i);

//   printf("%c\n", order[i + 2]);

//   if(order[i + 2] >= '0' && order[i + 2] <= '9'){
//     num = (order[i + 2] - '0') + ((order[i + 1] - '0')*10);
//       printf("1. %d\n", num);
//   }
//   else{
//     num = order[i + 1] - '0';
//       printf("2. %d\n", num);
//   }

  long long result = 0;

  for(int j = 0; j < i; j++){
    if(order[j] >= 'A' && order[j] <= 'Z'){
      order[j] = order[j] - 'A' + 10;
    }
    else if(order[j] >= '0' && order[j] <= '9'){
        order[j] = order[j] - '0';
    }
  }

  for(int j = 0; j < i; j++){
    result = result + order[i - 1 - j]*pow((double)num, (double)j);
  }

  printf("%lld", result);

  return 0;
}
