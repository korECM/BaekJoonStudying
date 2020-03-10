#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include <cmath>

using namespace std;

int main() {
#ifdef LOCAL
    freopen("input2.txt", "r", stdin);
#endif
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, b;
    cin >> n >> m >> b;
    vector<vector<int>> input(n, vector<int>(m));
    int maxi = 0;
    int mini = 256;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> input[i][j];
            maxi = max(maxi, input[i][j]);
            mini = min(mini, input[i][j]);
        }
    }
    long long time = 987654321987654321;
    int minHeight = 0;
    for (int height = mini; height <= maxi; height++) {
        long long sum = 0;
        long long tempTime = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                sum += height - input[i][j];
                tempTime += height > input[i][j] ? (height - input[i][j])
                                                 : 2 * (input[i][j] - height);
            }
        }
        if (sum > b)
            continue;
        if (time >= tempTime) {
            minHeight = max(minHeight, height);
        }
        if (time > tempTime) {
            time = tempTime;
        }
    }
    cout << time << " " << minHeight << endl;

#ifdef LOCAL
    fclose(stdin);
#endif

    return 0;
}