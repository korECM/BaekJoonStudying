#include <stdio.h>
#include <stdlib.h>

int min(int a, int b){
  if(a < b) return a;
  else return b;
}

int main(){
  int n, m;
  scanf("%d %d", &n, &m);

  char line[50][50];
  int changenum[2000][2];   //0은 B부터 시작, 1은 W부터 시작
  int count = 0;

  for(int i = 0; i < n; i++){
    scanf("%s", line[i]);
  }

  for(int i = 0; i < m - 7; i++){
    for(int j = 0; j < n - 7; j++){
      for(int p = i; p < i + 8; p++){
        for(int q = j; q < j + 8; q++){
          if( ((p + q)%2 == 0) && (line[p][q] != 'B') ){
            changenum[count][0]++;
          }
          if( ((p + q)%2 == 1) && (line[p][q] != 'W')){
            changenum[count][0]++;
          }
          if( ((p + q)%2 == 0) && (line[p][q] != 'W') ){
            changenum[count][1]++;
          }
          if( ((p + q)%2 == 1) && (line[p][q] != 'B')){
            changenum[count][1]++;
          }
        }
      }
      count++;
    }
  }

  int minnum1 = 64;
  int minnum2 = 64;

  printf("%d\n", count);

  for(int i = 0; i < count; i++){
    minnum1 = min(minnum1, changenum[i][0]);
    minnum2 = min(minnum2, changenum[i][1]);
  }

  printf("%d", min(minnum1, minnum2));

  return 0;
}