#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include <cmath>

using namespace std;

int n;
// long long solve(int n, int type){
//     if(n ==1) return 0;
//     if(n == 2) return 3;

// }

long long dp[31];

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    int n;
    cin >> n;
    if (n % 2 != 0) {
        cout << 0 << endl;
        return 0;
    }
    // dp[1][0] = 0;
    // dp[1][1] = 0;
    dp[2] = 3;
    dp[4] = 11;
    for (int i = 6; i <= n; i += 2) {
        dp[i] += dp[i -2] * 3;
        for (int j = 4; j <= i; j += 2) {
            dp[i] += dp[i - j] * 2;
        }
        dp[i] += 2;
    }
    cout << dp[n]<< endl;

    // cout << solve(n, 0) + solve(n, 1) << endl;

#ifdef LOCAL
    fclose(stdin);
#endif

    return 0;
}