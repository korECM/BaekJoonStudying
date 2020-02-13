#include <stdio.h>
#include <stdlib.h>

#define MAX_WORD 101

int main(){
  char word[MAX_WORD];
  char word_num[26];
  scanf("%s\n", word);

  for(int i = 0; i < strlen(word); i++){
    word_num[word[i] - 'a']++;
  }

  for(int i = 0; i < 26; i++){
    printf("%d ", word_num[i]);
  }

  return 0;
}
