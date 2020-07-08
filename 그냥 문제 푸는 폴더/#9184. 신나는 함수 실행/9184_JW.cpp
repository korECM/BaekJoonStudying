#include <string.h>

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long dp[51][51][51];

long long w(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        return 1;
    }
    if (dp[a][b][c] != -1) {
        return dp[a][b][c];
    }
    if (a > 20 || b > 20 || c > 20) {
        if (dp[20][20][20] != -1) {
            return dp[20][20][20];
        }
        return dp[20][20][20] = w(20, 20, 20);
    }
    if (a < b && b < c) {
        return dp[a][b][c] =
                   w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    }
    return dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) +
                         w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    int a, b, c;

    memset(dp, -1, sizeof(dp));

    while (true) {
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1) {
            return 0;
        }
        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c)
             << endl;
    }

#ifdef LOCAL
    fclose(stdin);
#endif

    return 0;
}