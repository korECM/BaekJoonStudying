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
    struct Node *next;//링크(다음 노드의 위치 정보)
}Node;

void InitList(Node **phead, Node **ptail);//초기화
void AddData(Node **phead, Node **tail, int data);//데이터 추가
void Remove(Node **phead, Node **ptail, Node *now);//노드 삭제

int main(){
   Node *head, *tail;
   
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
       
        for(int i = 1; i < delete_pos; i++){
           seek = seek->next;
        }
        printf("<%d, ", seek->data);
        Remove(&head, &tail, seek);
       
        for(int i = 2; i < size_num; i++){
            for(int j = 0; j < delete_pos; j++){
               seek = seek->next;
            }
            printf("%d, ", seek->data);
            Remove(&head, &tail, seek);
        }
       
        for(int i = 0; i < delete_pos; i++){
           seek = seek->next;
        }
        printf("%d>", seek->data);
        Remove(&head, &tail, seek);
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

    if (*phead == NULL)//빈 상태일 때
    {
        *phead = *ptail = now;
        return;
    }

    (*ptail)->next = now;//맨 뒤 노드의 next를 now로 설정
    now->next = (*phead); //now의 next를 맨 앞 노드로 설정
    *ptail = now; //맨 뒤 노드를 now로 설정


}

void Remove(Node **phead, Node **ptail, Node *now)
{
    Node *prev = NULL;
    Node *seek = *phead;

    if (*phead == now)//삭제할 노드가 맨 앞 노드와 같다면
    {
        free(*phead);//맨 앞 노드 메모리 해제
        *phead = *ptail = NULL;//이제 맨 앞 노드는 없음
        return;//함수 종료
    }

    while (seek != *ptail) //seek가 맨 마지막 노드가 아니면
    {
        if (seek == now)//seek가 now와 같을 때
        {
            prev->next = seek->next;//이전 노드의 next를 seek의 next로 설정
            free(seek);
            return;//함수 종료
        }
        prev = seek;//seek를 변경하기 전에 prev에 기억
        seek = seek->next;//seek를 다음으로 이동
    }

    //현재 seek는 *ptail과 같은 상태
    if (seek == now)//seek가 now와 같을 때
    {
        prev->next = seek->next;//이전 노드의 next를 seek의 next로 설정
        free(seek);
        *ptail = prev;//맨 마지막 노드를 prev로 설정
    }
}
