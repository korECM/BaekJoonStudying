#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 26

char board[MAX_SIZE][MAX_SIZE];
int area_size[625];


void search(char board_[][MAX_SIZE], int m, int n, int area_num){
    if(board_[m + 1][n] == '1'){
        area_size[area_num]++;
        board_[m][n] == '2';
        search(board_, m + 1, n, area_num);
    }
    if(board_[m - 1][n] == '1'){
        area_size[area_num]++;
        board_[m][n] == '2';
        search(board_, m - 1, n, area_num);
    }
    if(board_[m][n + 1] == '1'){
        area_size[area_num]++;
        board_[m][n] == '2';
        search(board_, m, n + 1, area_num);
    }
    if(board_[m][n - 1] == '1'){
        area_size[area_num]++;
        board_[m][n] == '2';
        search(board_, m, n - 1, area_num);
    }
}

int main(){
  int area = 0;

  int size;
  scanf("%d", &size);

  for(int i = 0; i < size; i++){
    scanf("%s", board[i]);
  }

  for(int i = 0; i < size; i++){
    for(int j = 0; j < size; j++){
        if(board[i][j] == '1'){ //새로운 영역 발견
            area++;             //영역 수 증가
            area_size[area]++;
            board[i][j] == '2';
            search(board, i, j, area);
        }
    }
  }

  int temp;

    for(int i = 1 ; i < area + 1; i++) {
         for(int j = 1 ; j < area - i  ; j++) {
                    if(area_size[j]>area_size[j+1]) {
                        temp = area_size[j];
                        area_size[j] = area_size[j+1];
                        area_size[j+1] = temp;
             }
        }
    }

    printf("%d\n", area);

    for(int i = 1; i < area + 1; i++){
        printf("%d\n", area_size[i]);
    }

  return 0;
}
