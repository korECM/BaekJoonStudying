#include <stdio.h>
#include <math.h>

long long numbers[10] = {0};

int main(){
    long long lastpage, lastpage_tmp = 0;
    scanf("%lld", &lastpage);
    lastpage_tmp = lastpage;

    int digit = 0;
    while(lastpage_tmp > 0){
        digit++;
        lastpage_tmp = lastpage_tmp/10;
    }

    long long ten = 0;
    long long nine = 0;

    if(digit < 3){
        //여긴 그냥 brute force로 해
        for(int i = 1; i < lastpage + 1; i++){
           int tmp = i;
           while(tmp > 0){
               numbers[tmp%10]++;
               tmp = tmp/10;
           }
        }
    }
    else{

        if(lastpage - pow(10.0, (double)(digit - 1)) <= pow(10.0, (double)digit) - lastpage){
            
            for(int i = 0; i < digit - 1; i++){
                ten = ten + pow(10.0, (double)i);
            }
            // printf("%lld\n", ten);

            for(int i = 0; i < digit - 2; i++){
                nine = nine + 9*pow(10.0, (double)i)*(i + 1);
            }
            // printf("%lld\n", nine);

            for(int i = 1; i < 10; i++){
                numbers[i] = ten + nine;
            }
            numbers[0] = nine;

            for(int i = pow(10.0, (double)(digit - 1)); i < lastpage + 1; i++){
                int tmp = i;
                while(tmp > 0){
                    numbers[tmp%10]++;
                    tmp = tmp/10;
                }
            }

        }else{
            
            // printf("%lld\n", ten);
            for(int i = 0; i < digit; i++){
                ten = ten + pow(10.0, (double)i);
            }
            // printf("%lld\n", ten);

            for(int i = 0; i < digit - 1; i++){
                nine = nine + 9*pow(10.0, (double)i)*(i + 1);
            }
            // printf("%lld\n", nine);

            for(int i = 1; i < 10; i++){
                numbers[i] = ten + nine;
            }
            numbers[0] = nine;

            for(int i = pow(10.0, (double)digit) - 1; i > lastpage; i--){
                int tmp = i;
                while(tmp > 0){
                    numbers[tmp%10]--;
                    tmp = tmp/10;
                }
            }


        }
        

        //예를 들면 input이 13000이면 9999까진 했으므로
        //10000 ~ 13000까지 브루트포스 돌려서 더해
        //근데 input이 99000이면 10000 ~99000 하는 것보다
        //99999해서 99001 ~ 99999를 빼는게 낫지.
        
    }
    
    // printf("%d\n", digit);

    for(int i = 0; i < 10; i++){
        printf("%lld ", numbers[i]);
    }

    return 0;
}