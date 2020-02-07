#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
using namespace std;

#define MAX_STACK_SIZE 10001
#define MAX_INT 100001
#define MAX 10001

int front=0;
int rear=0;
string queue[MAX];
char order[MAX_STACK_SIZE][15] = {{'N'}};

 
int IsEmpty(void){
    if(front==rear)//front와 rear가 같으면 큐는 비어있는 상태 
        return true;
    else return false;
}
int IsFull(void){
    int tmp=(rear+1)%MAX; //원형 큐에서 rear+1을 MAX로 나눈 나머지값이
    if(tmp==front)//front와 같으면 큐는 가득차 있는 상태 
        return true;
    else
        return false;
}
void addq(string value){
    if(IsFull())
        printf("Queue is Full.\n");
    else{
         rear = (rear+1)%MAX;
         queue[rear] = value;
        }

}
string deleteq(){
    if(IsEmpty())
        printf("-1\n");
    else{
        front = (front + 1) % MAX;
        return queue[front];
    }
}

int main(){
    int order_size = 0;
    int tmp = 0;
    
    scanf("%d\n", &order_size);
    //printf("??\n");
    
    for(int i = 0; i < order_size; i++){
        fgets(order[i], sizeof(order[i]), stdin);
    }
    
    string push_value;
    
    for(int i = 0; i < order_size; i++){
        int index_count = 5;
        
        if(!strncmp(order[i], "back", 3)){
            if(IsEmpty() == true){
                printf("-1\n");
            } else {
                printf("%s\n", queue[rear].c_str());
            }
        }
        else if(!strncmp(order[i], "size", 3)){
            printf("%d\n", (rear - front));
        }
        else if(!strncmp(order[i], "empty", 3)){
            printf("empty\n");
            printf("%d\n", IsEmpty());
        }
        else if(!strncmp(order[i], "pop", 3)){
            printf("%s\n", deleteq().c_str());
        }
        else if(!strncmp(order[i], "front", 3)){
            if(IsEmpty() == true){
                printf("-1\n");
            } else {
                printf("%s\n", queue[front + 1].c_str());
            }
        }
        else if(!strncmp(order[i], "push", 3)){
            for(int j = 5; j < 15; j++){
                //printf("%c", push_value[j - 5]);
                index_count++;
                //printf("%d\n", index_count);
                if(order[i][j + 1] == 'N'){
                    break;
                }
                
            }
            push_value.append(order[i], 5, index_count);
            
            addq(push_value);
        }
    }
    
    return 0;
}
