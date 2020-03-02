#include <string.h>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n, limit;
    cin >> n;
    int result = 0;
    vector<int> dp(100001, 987654321);
    for (int i = 1; i < 317; i++) {
        dp[i * i] = 1;
    }
    for (int i = 2; i <= n; i++) {
        if (dp[i] == 987654321) {
            limit = sqrt(i);
            for (int j = limit; j > 0; j--) {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
    }
    cout << dp[n] << endl;

    return 0;
}