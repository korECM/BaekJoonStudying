#include <stdio.h>
#include <stdlib.h>

int main() {
    long long size;
    long long number[10000001];
    scanf("%lld", &size);

    long long tmp;

    for(long long i = 0; i < size ; i++){
        scanf("%lld", &tmp);
        number[tmp]++;
        if(number[tmp] > 1){
            printf("%lld", tmp);
            break;
        }
    }

    return 0;
}