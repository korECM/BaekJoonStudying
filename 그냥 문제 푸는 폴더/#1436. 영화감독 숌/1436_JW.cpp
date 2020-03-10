#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    int n;
    cin >> n;
    vector<int> dp(10001, 0);
    int index = 1;
    int num = 666;
    while(index <= 10000){
        if(to_string(num).find("666") != string::npos){
            dp[index++] = num;
        }
        num++;
    }
    cout << dp[n] << endl;
#ifdef LOCAL
    fclose(stdin);
#endif

    return 0;
}