#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<bool>> map(302, vector<bool>(302, false));
vector<vector<int>> d(302, vector<int>(302, 0));

int solve(int x, int y, int count) {
    int maximum = 0;
    for (int i = 1; i < 302; i++) {
        for (int j = 1; j < 302; j++) {
            if (map[i][j]) {
                d[i][j] = max(d[i - 1][j], d[i][j - 1]) + count - i - j + 2;
            } else {
                d[i][j] = max(d[i - 1][j], d[i][j - 1]);
            }
            maximum = max(maximum, d[i][j]);
        }
    }
    return maximum;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int n, m;
    cin >> n >> m;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        cin.ignore();
        map[y + 1][x + 1] = true;
    }
    cout << solve(1, 1, m) << endl;

#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif

    return 0;
}