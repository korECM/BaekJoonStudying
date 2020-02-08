#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include "stdlib.h"
#define ARR_MAX 1000
using namespace std;


int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<int> vt;
    int n = 0; //입력받을 벡터의 크기
    int arr[ARR_MAX] = {0};
    int ans = 0;    //정답 값
    
    vt.push_back(-1);
    //scanf("%d", &n);
    cin >> n;
    
    for(int i = 0; i<n; i++){
        //scanf("%d", &arr[i]);
        cin >> arr[i];
    }

    for(int i = 0; i<n;i++){
        if(vt.back() < arr[i]){
            vt.push_back(arr[i]);
            ans++;
        }
        else{
            auto it = lower_bound(vt.begin(), vt.end(), arr[i]);
            *it = arr[i];
        }
    }
    
    //printf("%d", ans);
    cout << ans;
    
    return 0;
}
