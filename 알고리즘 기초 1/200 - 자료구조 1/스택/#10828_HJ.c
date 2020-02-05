#include <stdio.h>
#include <string.h>

#define MAX_STACK_SIZE 10001
#define MAX_INT 100001

int stack[MAX_STACK_SIZE];

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

void push(int value){
    if(IsFull() == 1){
        printf("Stack is full!");
    } else {
        stack[++top] = value;
    }
}

int pop(){
    if(IsEmpty() == 1){
        printf("-1");
    } else {
        return stack[top--];
    }
}

int top_print(){
    if(IsEmpty() == 1){
        printf("-1");
    } else {
        return stack[top];
    }
}

int main(){
    int order_size = 0;
    char* order[MAX_STACK_SIZE] = {0};
    
    scanf("%d", &order_size);
    printf("??\n");
    
    int tmp = 0;
    
    for(int i = 0; i < order_size; i++){
        scanf("%s", &order[i]);
        getchar();
        if(order[i] == "push"){
            scanf("%d", &tmp);
            push(tmp);
        }
        printf("%d\n", i);
    }
    
    for(int i = 0; i < order_size; i++){
        if(order[i] == "top"){
            printf("%d\n", top_print());
        }
        else if(order[i] == "size"){
            printf("%d\n", top + 1);
        }
        else if(order[i] == "empty"){
            printf("%d\n", IsEmpty());
        }
        else if(order[i] == "pop"){
            printf("%d\n", pop());
        }
    }
    
    return 0;
}
