#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>

int main(){
    char word[101], word1[101], word2[101];

    scanf("%s", word);

    int length = strlen(word);

    for(int i = 0; i < length; i++){
        word1[i] = word[i];
        word2[i] = word[length - i -1];
    }

    int pel = 1;

    for(int i = 0; i < length; i++){
        if(word1[i] != word2[i]){
            printf("0");
            pel = 0;
            break;
        }
    }

    if(pel == 1){
        printf("1");
    }


    return 0;
}