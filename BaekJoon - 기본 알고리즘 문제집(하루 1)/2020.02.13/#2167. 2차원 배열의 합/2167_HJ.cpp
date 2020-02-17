#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 301
#define MAX_SIZE2 90601
#define MAX_NUM 10001

int main(){
  int n, m; //행, 열
  int index[MAX_SIZE][MAX_SIZE];
  int dp[MAX_SIZE2];
  dp[0] = 0;
  scanf("%d %d", &n, &m);
  for(int i = 1; i < n + 1; i++){
    for(int j = 1; j < m + 1; j++){
      scanf("%d", &index[i][j]);
      dp[(i - 1)*m + j] = dp[(i - 1)*m + j - 1] + index[i][j];
    }
  }

  int part_num = 0;
  scanf("%d", &part_num);

  int num_i[MAX_NUM];
  int num_j[MAX_NUM];
  int num_x[MAX_NUM];
  int num_y[MAX_NUM];

  for(int i = 0; i < part_num; i++){
    scanf("%d %d %d %d", &num_i[i], &num_j[i], &num_x[i], &num_y[i]);
  }

  for(int i = 0; i < part_num; i++){
    printf("%d\n", (dp[(num_x[i] - 1) * m + num_y[i]]) - (dp[(num_i[i] - 1) * m + num_j[i] - 1]));
  }

  return 0;
}
