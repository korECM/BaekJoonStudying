#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include <cmath>

using namespace std;

int map[11][11];

int solve(int n, int k) {
    if(k == 0 || n == k) return 1;
    int& ret = map[n][k];
    if(ret != -1) return ret;
    return ret = solve(n - 1, k) + solve(n - 1, k - 1);
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    int n, k;
    cin >> n >> k;
    memset(map, -1, sizeof(map));
    cout << solve(n, k) << endl;

#ifdef LOCAL
    fclose(stdin);
#endif

    return 0;
}