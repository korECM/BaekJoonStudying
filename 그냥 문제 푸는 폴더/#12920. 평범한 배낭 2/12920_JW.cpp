#include <string.h>

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> input(3000);
int n, m, temp1, temp2, temp3;
int dp[3000][10'001];
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
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    int index = 0;
    int limit = n;
    for (int i = 0; i < limit; i++) {
        cin >> temp1 >> temp2 >> temp3;
        for (int j = 1; temp3 > 0; j *= 2) {
            int ix = min(temp3, j);
            input[index++] = {temp1 * ix, temp2 * ix};
            temp3 -= ix;
        }
        // cout << index << "\n";
    }
    n = index + 1;
    cout << solve(0, m, input) << endl;

#ifdef LOCAL
    fclose(stdin);
#endif

    return 0;
}
