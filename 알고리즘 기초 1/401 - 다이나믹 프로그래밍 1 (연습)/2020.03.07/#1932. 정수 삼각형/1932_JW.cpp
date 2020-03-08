#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include <cmath>

using namespace std;

vector<vector<int>> input(500, vector<int>(500));
int map[500][500];
int n;

int solve(int x, int y) {
    if (x >= n || y >= n)
        return 0;
    int& ret = map[y][x];
    if (ret != -1)
        return ret;
    return ret = (max(solve(x, y + 1), solve(x + 1, y + 1)) + input[y][x]);
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    memset(map, -1, sizeof(map));
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> input[i][j];
        }
    }

    cout << solve(0, 0) << endl;

#ifdef LOCAL
    fclose(stdin);
#endif

    return 0;
}