#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <string>
#include <iostream>
using namespace std;

#define MAX_LENGTH 100001
#define MAX_ORDER 500001

typedef struct Node//노드 정의
{
    int data;//데이터
    int delete_done;//지워지면 1
    struct Node *next;//링크(다음 노드의 위치 정보)
}Node;

void InitList(Node **phead, Node **ptail);//초기화
void AddData(Node **phead, Node **tail, int data);//데이터 추가

int main(){
   Node *head, *tail;
   int trynum = 0;
   
   InitList(&head, &tail);
   
   int size_num = 0;
   int delete_pos = 0;
   scanf("%d %d", &size_num, &delete_pos);
   
   if(size_num == 1){
       printf("<1>");
   }else{
        for(int i = 1; i < size_num + 1; i++){
           AddData(&head, &tail, i);
        }
       
        Node *seek = head;

        //  for(int i = 1; i < size_num + 1; i++){
        //    seek = seek->next;
        //    printf("%d->", seek->delete_done);
        // }
        // printf("\n");
       
        for(int i = 1; i < delete_pos; i++){
           seek = seek->next;
        }
        printf("<%d, ", seek->data);
        seek->delete_done = 1;
       
        for(int i = 2; i < size_num; i++){
            while(trynum < delete_pos){
              if(seek->delete_done == 0){
                seek = seek->next;
                trynum++;
              }
            }
            printf("%d, ", seek->data);
            seek->delete_done = 1;
            trynum = 0;
        }
       
        while(trynum < delete_pos){
          if(seek->delete_done == 0){
            seek = seek->next;
            trynum++;
          }
        }
        printf("%d>", seek->data);
        seek->delete_done = 1;
   }
    return 0;
}

void InitList(Node **phead, Node **ptail)
{
    *phead = NULL;
    *ptail = NULL;
}

void AddData(Node **phead, Node **ptail, int data)
{
    Node *now = (Node *)malloc(sizeof(Node));//새로운 노드 생성
    now->data = data; //생성한 노드에 data 설정
    now->delete_done = 0;

    if (*phead == NULL)//빈 상태일 때
    {
        *phead = *ptail = now;
        return;
    }

    (*ptail)->next = now;//맨 뒤 노드의 next를 now로 설정
    now->next = (*phead); //now의 next를 맨 앞 노드로 설정
    *ptail = now; //맨 뒤 노드를 now로 설정
}
