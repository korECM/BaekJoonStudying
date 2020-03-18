#include <string.h>

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, k, temp1, temp2;
int dp[101][100001];
int solve(int index, int remain, vector<pair<int, int>>& input) {
    if (index == n)
        return 0;
    int& ret = dp[index][remain];
    if (ret != -1)
        return ret;
    int maxi = solve(index + 1, remain, input);
    if (remain >= input[index].first)
        maxi = max(maxi, solve(index + 1, remain - input[index].first, input) +
                             input[index].second);
    return ret = maxi;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    cin >> n >> k;
    vector<pair<int, int>> input(n);
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++) {
        cin >> temp1 >> temp2;
        input[i] = {temp1, temp2};
    }

    cout << solve(0, k, input) << endl;

#ifdef LOCAL
    fclose(stdin);
#endif

    return 0;
}