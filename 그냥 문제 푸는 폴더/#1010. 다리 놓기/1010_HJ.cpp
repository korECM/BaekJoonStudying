#include <stdio.h>
#include <stdlib.h>

int main(){
    int test_case = 0;
    scanf("%d", &test_case);

    for(int i = 0; i < test_case; i++){
        int n = 0;
        int m = 0;
        scanf("%d %d", &n, &m);

        long long result = 0;
        long long up = 1;
        long long down = 1;
        
        if(n > m/2){
            n = m - n;
        }

        for(int j = 0; j < n; j++){
            up = up*(m - j);
            down = down*(j + 1);
        }
        result = up/down;
        printf("%lld\n", result);
        
    }

    return 0;
}