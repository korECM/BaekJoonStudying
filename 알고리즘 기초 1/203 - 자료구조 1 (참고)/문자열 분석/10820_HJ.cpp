#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD 201

int main(){
  char word[MAX_WORD];
    while (fgets(word, sizeof(word), stdin)!=NULL)
    {
        word[strlen(word) - 1] = 0;
        int capital = 0, small = 0, number = 0, empty = 0;
        for (int i = 0; i < strlen(word); ++i)
        {
            if (word[i] >= 'A' && word[i] <= 'Z')
                ++capital;
            else if (word[i] >= 'a' && word[i] <= 'z')
                ++small;
            else if (word[i] >= '0' && word[i] <= '9')
                ++number;
            else
                ++empty;
        }
        printf("%d %d %d %d\n", small, capital, number, empty);
    }

  return 0;
}
