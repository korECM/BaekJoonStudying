#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD 101

int main(){
  char word[MAX_WORD];
    gets(word);

  for(int i = 0; i < strlen(word); i++){
    if(word[i] >= 'a' && word[i] <= 'z'){
      word[i] = 'a' + (word[i] - 'a' + 26 + 13)%26;
    }
    else if(word[i] >= 'A' && word[i] <= 'Z'){
      word[i] = 'A' + (word[i] - 'A' + 26 + 13)%26;
    }
  }

  for(int i = 0; i < strlen(word); i++){
    printf("%c", word[i]);
  }

  return 0;
}
