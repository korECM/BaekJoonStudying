#include <stdio.h>
#include <string.h>

#define MAX_STACK_SIZE 51
#define MAX_INT 1000001

char stack[MAX_INT][MAX_STACK_SIZE];
char PS[MAX_INT][MAX_STACK_SIZE];

int top[MAX_INT] = {-1};

int IsEmpty(int i){
    if(top[i] < 0){
        return 1;
    }
    else{
        return 0;
    }
}

int IsFull(int i){
    if(top[i] >= MAX_STACK_SIZE - 1){
        return 1;
    } else {
        return 0;
    }
}

void push(int i, char value){
    if(IsFull(i) == 1){
        printf("Stack is full!");
    } else {
        stack[i][++top[i]] = value;
    }
}

char pop(int i){
    if(IsEmpty(i) == 1){
        return -1;
    } else {
        return stack[i][top[i]--];
    }
}

char peak(int i){
    if(IsEmpty(i) == 1){
        return -1;
    } else {
        return stack[i][top[i]];
    }
}

int main(){
    int order_size = 0;
    char oper[MAX_STACK_SIZE] = {'\0'}; 
    scanf("%d\n", &order_size);
    
    for(int i = 0; i < order_size; i++){
        fgets(PS[i], sizeof(PS[i]), stdin);
    }
    
    for(int i = 0; i < order_size; i++){
        int yes = 1;
        for(int j = 0; j < MAX_INT; j++){
            if(PS[i][j] == '('){
                push(i, '(');
                //printf("%c", peak(i));
            }else if(PS[i][j] == ')'){
                top[i]--;
                //printf(")");
            }else{
                break;
            }
            
            if((PS[i][j + 1] ==')') && (top[i] == -1)){
                printf("NO\n");
                yes = 0;
                break;
            }
            else if(top[i] < -1){
                printf("NO\n");
                yes = 0;
                break;
            }
            
        }
            if(yes == 1 && top[i] != 0){
               // printf("    %d  ", top[i]);
                printf("NO\n");
                yes = 0;
            }
            else if(yes == 1){
                printf("YES\n");
            }
    }
    
   
    
    
    return 0;
}