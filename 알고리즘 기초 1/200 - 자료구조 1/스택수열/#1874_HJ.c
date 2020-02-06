#include <stdio.h>
#include <string.h>

#define MAX_STACK_SIZE 1000001
#define MAX_INT 1000001

int stack[MAX_STACK_SIZE];
int stack2[MAX_STACK_SIZE];

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
        return -1;
    } else {
        return stack[top--];
    }
}

int peak(){
    if(IsEmpty() == 1){
        return -1;
    } else {
        return stack[top];
    }
}

int main(){
    int order_size = 0;
    char oper[MAX_STACK_SIZE] = {'\0'}; 
    scanf("%d\n", &order_size);
    
    //for(int i = 0; i < order_size; i++){
    //    push(i + 1);
    //}
    
    for(int i = 0; i < order_size; i++){
        scanf("%d", &stack2[i]);
    }
    
    push(1);
    //printf("+\n");
    oper[0] = '+';
    int trynum = 2;
    int all = 1;
    
    for(int i = 0; i < order_size; i++){
        while(trynum < order_size + 2){
            if(peak() == stack2[i]){
                top--;
                //printf("-\n");
                oper[all] = '-';
                all++;
                break;
            }
            push(trynum);
            oper[all] = '+';
            all++;
            //printf("+\n");
            trynum++;
        }
    }
    
    if(all != 2*order_size){
        printf("NO");
    } else {
        for(int i = 0; i < all; i++){
            printf("%c\n", oper[i]);
        }
    }
    
    
    return 0;
}
