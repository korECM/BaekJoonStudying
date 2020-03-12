#include <stdio.h>
#include <stdlib.h>

int min_val(int A, int B){
    if(A < B) return A;
    else return B;
}

int main(){
    int a, b, c, m, n;
    scanf("%d %d %d %d %d", &a, &b, &c, &m, &n);

    int result = 50;
    int min_bur;
    min_bur = min_val(a, b);
    min_bur = min_val(min_bur, c);

    int min_dr;
    min_dr = min_val(m, n);

    result = result + min_bur + min_dr;

    printf("%d", result);

    return 0;
}