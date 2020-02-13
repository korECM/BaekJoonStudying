#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <string.h>
#include <iostream>

using namespace std;

#define MAX_LENGTH 101

int main(){
    int op[50] = {0};
    op['('] = 0;
    op['+'] = 1;
    op['-'] = 1;
    op['*'] = 2;
    op['/'] = 2;

  char inorder_input[MAX_LENGTH];
  stack<char>s;

  scanf("%s", inorder_input);

  for(int i = 0; i < strlen(inorder_input); i++){
    if(inorder_input[i] >= 'A' && inorder_input[i] <= 'Z'){
      printf("%c", inorder_input[i]);
    }
    else if(inorder_input[i] == '('){
      s.push(inorder_input[i]);
    }
    else if(inorder_input[i] == ')'){
      while(s.top() != '('){
        printf("%c", s.top());
        s.pop();
      }
      s.pop();
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

  while(s.size() != 0){
    printf("%c", s.top());
    s.pop();
  }

  return 0;
}
