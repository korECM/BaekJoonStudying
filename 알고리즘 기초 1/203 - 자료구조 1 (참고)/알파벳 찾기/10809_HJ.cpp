#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD 101

int main(){
  char word[MAX_WORD];
  int word_first_pos[26] = {-1};
  scanf("%s", word);

    for(int i = 0; i < 26; i++){
        word_first_pos[i] = -1;
    }

  for(int i = 0; i < strlen(word); i++){
    if(word_first_pos[word[i] - 'a'] == -1){
      word_first_pos[word[i] - 'a'] = i;
    }
  }

  for(int i = 0; i < 26; i++){
    printf("%d ", word_first_pos[i]);
  }

  return 0;
}
