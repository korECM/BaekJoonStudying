#include <stdio.h>
#include <stdlib.h>
#include <stack>
#define MAX_STACK_SIZE 1000001

using namespace std;

int bigger(int a, int b){
  if(a > b) return a;
  else return b;
}

int main(){
  int value_arr[MAX_STACK_SIZE] = {0};
  int F_arr[MAX_STACK_SIZE] = {0};
  int biggest_value = 0;
  int stack_size = 0;
  int value = 0;
  stack<int>s;

  cin >> stack_size;

  for(int i = 0; i < stack_size; i++){
    scanf("%d", &value_arr[i]);
  }

  for(int i = 0; i < stack_size; i++){
    biggest_value = bigger(biggest_value, value_arr[i]);
  }

  for(int i = 0; i < stack_size; i++){
    for(int j = 0; j < biggest_value; j++){
      printf("무언가 잘못되고 있음.\n", );
    }
  }


  return 0;
}
