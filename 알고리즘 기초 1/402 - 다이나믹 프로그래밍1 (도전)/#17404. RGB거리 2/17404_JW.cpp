#include <iostream>
#include <vector>

using namespace std;
int n;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    cin >> n;
    vector<vector<int>> input(n, vector<int>(3));
    for (int i = 0; i < n; i++) {
        cin >> input[i][0] >> input[i][1] >> input[i][2];
    }
    int mini = 987654321;
    int dp[1001][3];
    for (int i = 0; i < n; i++) {
        dp[i][0] = 987654321;
        dp[i][1] = 987654321;
        dp[i][2] = 987654321;
    }

    for (int ii = 0; ii < 3; ii++) {
        int firstColor = ii;
        dp[0][0] = 987654321;
        dp[0][1] = 987654321;
        dp[0][2] = 987654321;
        dp[0][firstColor] = input[0][firstColor];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                if (i == n - 1 && j == firstColor)
                    continue;
                dp[i][j] = min(dp[i - 1][(j + 1) % 3] + input[i][j],
                               dp[i - 1][(j + 2) % 3] + input[i][j]);
            }
        }
        for (int j = 0; j < 3; j++) {
            if (j == firstColor)
                continue;
            mini = min(mini, dp[n - 1][j]);
        }
    }

    cout << mini << endl;

#ifdef LOCAL
    fclose(stdin);
#endif

    return 0;
}