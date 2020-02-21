#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define MAX_SIZE 301

int distance(int a, int b, int x, int y){
  int result;
  result = abs(x - a) + abs(y - b);
  return result;
}

int main(){
  int valueN, valueM;
  int dote_visit[MAX_SIZE][4];
  scanf("%d %d", &valueN, &valueM);

  int tmp_x, tmp_y;

  for(int i = 0; i < valueN; i++){
    scanf("%d %d", &tmp_x, &tmp_y);
    dote_visit[i][0] = tmp_x;
    dote_visit[i][1] = tmp_y;
    dote_visit[i][2] = -1;
    dote_visit[i][3] = valueM;
  }

  int total_candy = 0;
  int start_x, start_y = 0;

  int tmp = 600;
  int tmp_i = -1;
  for(int j = 0; j < valueN; j++){
    for(int i = 0; i < valueN; i++){
      if((dote_visit[i][2] == -1) && (tmp > distance(start_x, start_y, dote_visit[i][0], dote_visit[i][1]))){
        tmp_i = i;
        tmp = min(tmp, distance(start_x, start_y, dote_visit[i][0], dote_visit[i][1]));
      }
    }

    dote_visit[tmp_i][2] = 1;
    total_candy = total_candy + dote_visit[tmp_i][3];
    dote_visit[tmp_i][3] = 0; //들른 곳은 먹었으니 0으로 초기화

    for(int i = 0; i < valueN; i++){
      if(dote_visit[i][3] <= 0){
        dote_visit[i][3] = 0;
        break;
      }
      if(dote_visit[i][2] == -1 && dote_visit[i][3] > 0){
        dote_visit[i][3] = dote_visit[i][3] - tmp;
      }
    }
  }

  printf("%d", total_candy);

  return 0;
}
