#include <string.h>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#define MAX 987654321
using namespace std;

int main() {
#ifdef LOCAL
    // freopen("input.txt", "r", stdin);
#endif

    int n;
    cin >> n;
    int dp[50001];
    dp[0] = 0;
    dp[1] = 1;
    // int limit = (int)sqrt(n);
    for (int i = 2; i <= n; i++) {
        dp[i] = 4;
        for (int j = 1; i - j * j >= 0; j++) {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }

    cout << dp[n] << endl;

#ifdef LOCAL
    // fclose(stdin);
#endif

    return 0;
}