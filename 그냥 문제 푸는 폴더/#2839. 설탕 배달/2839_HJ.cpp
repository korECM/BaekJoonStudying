#include <stdio.h>
#include <stdlib.h>

int main(){
    int input;
    scanf("%d", &input);

    int result = 0;
    int tmp = input;

    while((tmp%5) != 0 && (tmp >= 0)){
        tmp = tmp - 3;
        result = result + 1;
    }

    while(tmp > 2){
      tmp = tmp - 5;
      result = result + 1;
    }

    if(tmp == 0){
      printf("%d", result);
    }
    else {
      printf("-1");
    }

    return 0;
}

// #include <stdio.h>
// #include <stdlib.h>

// int main(){
//     int input;
//     scanf("%d", &input);

//     int result = 0;
//     int tmp = input;

//     while(tmp > 12){
//         tmp = tmp - 5;
//         result = result + 1;
//     }

//     if((tmp % 3) == 0){
//         result = (tmp / 3);
//     }else{
//         if(tmp == 8 || tmp == 10){
//             result += 2;
//         }else if(tmp ==11){
//             result += 3;
//         }else if(tmp == 5){
//             result++;
//         }else{
//             result = -1;
//         }
//     }

//     printf("%d", result);

//     return 0;
// }