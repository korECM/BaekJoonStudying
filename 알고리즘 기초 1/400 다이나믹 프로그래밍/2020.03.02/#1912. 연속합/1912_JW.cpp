#include <string.h>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n;
long long solve(vector<int>& input) {
    vector<long long> dp(n, 0);
    dp[0] = input[0];
    long long maxi = input[0];
    for (int i = 1; i < n; i++) {
        dp[i] = input[i];
        if (dp[i - 1] > 0) {
            dp[i] += dp[i - 1];
        }
        maxi = max(maxi, dp[i]);
    }
    return maxi;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    cin >> n;
    vector<int> input(n);
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }
    cout << solve(input) << endl;

#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif

    return 0;
}