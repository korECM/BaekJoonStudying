#include <string.h>

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    int t, n;
    cin >> t;
    long long dp[101];
    memset(dp, -1, sizeof(dp));
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 2;
    for (int j = 6; j < 101; j++) {
        dp[j] = dp[j - 1] + dp[j - 5];
    }
    for (int i = 0; i < t; i++) {
        cin >> n;
        cout << dp[n] << endl;
    }

#ifdef LOCAL
    fclose(stdin);
#endif

    return 0;
}