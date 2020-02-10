#include <stdio.h>
#include <string.h>

#define MAX_STACK_SIZE 21
#define MAX_SENTENCE_LENGTH 1001
#define MAX_SENTENCE_NUM 1001

char stack[MAX_STACK_SIZE];
char sentence[MAX_SENTENCE_NUM][MAX_SENTENCE_LENGTH]={0};

int top = -1;

int IsEmpty(){
    if(top < 0){
        return 1;
    }
    else{
        return 0;
    }
}

int IsFull(){
    if(top >= MAX_STACK_SIZE - 1){
        return 1;
    } else {
        return 0;
    }
}

void push(char letter){
    if(IsFull() == 1){
        printf("Stack is full!");
    } else {
        stack[++top] = letter;
    }
}

char pop(){
    if(IsEmpty() == 1){
        printf("Stack is empty!");
    } else {
        return stack[top--];
    }
}

int main(){
    int num_of_sentence = 0;
    int c;
    scanf("%d\n", &num_of_sentence);

    for(int i = 0; i < num_of_sentence; i++){
        //gets(sentence[i]);
        fgets(sentence[i], sizeof(sentence[i]), stdin);
        //while(c = getchar() != '\n' && c != EOF);
    }

    for(int i = 0; i < num_of_sentence; i++){
        for(int j = 0; j < strlen(sentence[i]); j++){
            if(sentence[i][j] == ' ' || sentence[i][j + 1] == 0){
                while(top >= 0){
                    printf("%c", pop());
                }
                printf(" ");
            } else {
                push(sentence[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}
