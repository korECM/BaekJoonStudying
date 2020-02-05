#include <stdio.h>
#include <string.h>

#define MAX_STACK_SIZE 10001
#define MAX_INT 100001

char* stack[MAX_STACK_SIZE];
char order[MAX_STACK_SIZE][15] = {{'N'}};


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

void push(char* value){
    if(IsFull() == 1){
        printf("Stack is full!");
    } else {
        stack[++top] = value;
    }
}

char* pop(){
    if(IsEmpty() == 1){
        return "-1";
    } else {
        return stack[top--];
    }
}

char* top_print(){
    if(IsEmpty() == 1){
        return "-1";
    } else {
        return stack[top];
    }
}

int main(){
    int order_size = 0;
    int tmp = 0;
    
    scanf("%d\n", &order_size);
    //printf("??\n");
    
    for(int i = 0; i < order_size; i++){
        fgets(order[i], sizeof(order[i]), stdin);
        //gets(order[i]);
        //getchar();
        //if(!strncmp(order[i], "push", 3)){
        //    scanf("%d", &tmp);
        //    push(tmp);
        //}
        //printf("%d\n", i);
        //printf("%d\n", strcmp(order[i], (char *)"top"));
    }
    
    char push_value[6] = {' '};
    
    
    for(int i = 0; i < order_size; i++){
        if(!strncmp(order[i], "top", 3)){
            printf("%s\n", top_print());
        }
        else if(!strncmp(order[i], "size", 3)){
            printf("%d\n", top + 1);
        }
        else if(!strncmp(order[i], "empty", 3)){
            printf("%d\n", IsEmpty());
        }
        else if(!strncmp(order[i], "pop", 3)){
            printf("%s\n", pop());
        }
        else if(!strncmp(order[i], "push", 3)){
            for(int j = 5; order[i][j] != 'N'; j++){
                push_value[j-5] = order[i][j];
                //if(order[i][j + 1] == 'N'){
                //    break;
                //}
            }
            //push_value = "123";
            //printf("%s", push_value);
            push(push_value);
        }
    }
    
    return 0;
}
