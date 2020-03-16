#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include <cmath>

using namespace std;

int dp[40][40];

int find(int n, int m) {
    int& ret = dp[n][m];
    if (ret != -1)
        return ret;
    if (m == 0 || n == 0)
        return ret = 1;
    ret = find(n - 1, m);
    if (m > 0)
        ret += find(n - 1, m - 1);
    return ret;
}
long long n, l, i;
string result;
void solve(int n, int m, int k, int p) {
    if (n == 0)
        return;
    if (m == 0) {
        for (int i = 0; i < n; i++) {
            result[p + i] = '0';
        }
        return;
    }
    int pivot = find(n - 1, m);
    if (k < pivot) {
        result[p] = '0';
        solve(n - 1, m, k, p + 1);
    } else {
        result[p] = '1';
        solve(n - 1, m - 1, k - pivot, p + 1);
    }
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    memset(dp, -1, sizeof(dp));
    cin >> n >> l >> i;
    result.resize(n);
    // find(n, l);

    solve(n, l, i - 1, 0);
    cout << result << endl;

#ifdef LOCAL
    fclose(stdin);
#endif

    return 0;
}