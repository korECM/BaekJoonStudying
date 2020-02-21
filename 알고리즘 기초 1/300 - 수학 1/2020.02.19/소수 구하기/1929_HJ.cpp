#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int main(){
    int begin, end;
    scanf("%d %d",&begin, &end);

    bool *c = new bool[end+1];

    c[1] = true;
    
    for(int i = 2; i*i<= end; i++){
        if(c[i] == false){
            for(int j = i * i; j <= end; j+=i){
                c[j] = true;
            }
        }
    }

    for(int i = begin; i <= end; i++){
      if(c[i] == false){
        printf("%d\n",i);
      }
    }

    delete c;
    return 0;
}
