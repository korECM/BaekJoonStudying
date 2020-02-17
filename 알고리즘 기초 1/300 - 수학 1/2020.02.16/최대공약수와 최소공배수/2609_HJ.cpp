#include <stdio.h>
#define MAX_SIZE 10001

int gcd(int x, int y){  //최대공약수
  int x_cd[MAX_SIZE];
  int y_cd[MAX_SIZE];
  int result = 1;

  int index_num_x, index_num_y = 0;

    for(int i = 1; i < x + 1; i++){
      if((x % i) == 0){
        x_cd[index_num_x] = i;
        //printf("%d ", x_cd[index_num_x]);
        index_num_x++;
      }
    }

    //printf("\n");

    for(int i = 1; i < y + 1; i++){
      if((y % i) == 0){
        y_cd[index_num_y] = i;
        //printf("%d ", y_cd[index_num_y]);
        index_num_y++;
      }
    }

    //printf("\n");

    for(int i = index_num_x - 1; i > -1; i--){
      for(int j = index_num_y - 1; j > -1; j--){
        if(x_cd[i] == y_cd[j]){
          result = x_cd[i];
          break;
        }
      }
      if(result == x_cd[i]) break;
    }

    return result;
}

int lcm(int x, int y){  //최소공배수
  int x_cm[MAX_SIZE];
  int y_cm[MAX_SIZE];
  int result;

  for(int i = 0; i < y; i++){
    x_cm[i] = x * (i + 1);
  }

  for(int i = 0; i < x; i++){
    y_cm[i] = y * (i + 1);
  }

  for(int i = 0; i < y; i++){
    for(int j = 0; j < x; j++){
      if(x_cm[i] == y_cm[j]){
        result = x_cm[i];
        break;
      }
    }
    if(result == x_cm[i]) break;
  }

  return result;
}

int main(){

	int a, b;

	scanf("%d %d", &a, &b);

	printf("%d\n%d", gcd(a, b), lcm(a, b));
	return 0;
}
