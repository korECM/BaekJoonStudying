#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD 101

int main(){
  char word[MAX_WORD];
  scanf("%s", word);

  printf("%d", (int)strlen(word));

  return 0;
}
