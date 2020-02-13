#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <string.h>
#include <iostream>

using namespace std;

#define MAX_LENGTH 101

int main(){
  int cal_num_size = 0;
  int cal_num[MAX_LENGTH] = {0};

  char postorder_input[MAX_LENGTH];
  stack<char>s;

  scanf("%d\n", cal_num_size);
  scanf("%s", postorder_input);

  for(int i = 0; i < cal_num_size; i++){
    scanf("%d", &cal_num[i]);
  }

  for(int i = 0; i < strlen(postorder_input); i++){
    s.push(postorder_input[i]);
  }

  for(int i = 0; i < strlen(postorder_input); i++){
    if(inorder_input[i] >= 'A' && inorder_input[i] <= 'Z'){
      printf("%c", inorder_input[i]);
    }
    else{
        // if(inorder_input[i] == '*' || inorder_input[i] == '/'){
        //     while((s.top() == '*' || s.top() == '/') && s.size() != 0){
        //         printf("%c", s.top());
        //         s.pop();
        //     }
        //     s.push(inorder_input[i]);
        // }
        // else{
        //     while(s.size() != 0 && s.top() != '('){
        //         printf("%c", s.top());
        //         s.pop();
        //     }
        //     s.push(inorder_input[i]);
        // }
        while(s.size() != 0 && op[s.top()] >= op[inorder_input[i]]){
            printf("%c", s.top());
            s.pop();
        }
        s.push(inorder_input[i]);
    }
  }



  return 0;
}
