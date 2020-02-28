#include <string.h>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int m, n;

void findWay(vector<vector<int>>& map,
             vector<vector<bool>>& visited,
             int x,
             int y,
             int num) {
    if (x < 0 || y < 0 || x >= n || y >= m)
        return;
    if (visited[y][x])
        return;
    int& ret = map[y][x];
    visited[y][x] = true;
    if (ret == 0) {
        ret = num;
        findWay(map, visited, x + 1, y, num);
        findWay(map, visited, x, y + 1, num);
        findWay(map, visited, x, y - 1, num);
        findWay(map, visited, x - 1, y, num);
    }
}

void solve(vector<vector<int>>& map, vector<vector<bool>>& visited) {
    int num = 2;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == 0) {
                findWay(map, visited, j, i, num);
                num++;
            }
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input2.txt", "r", stdin);
#endif

    cin >> m >> n;
    cin.ignore();
    string input;
    vector<vector<int>> map(m, vector<int>(n));
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    for (int i = 0; i < m; i++) {
        cin >> input;
        for (int j = 0; j < n; j++) {
            map[i][j] = input[j] - '0';
        }
    }
    solve(map, visited);
    // for (int i = 0; i < m; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << map[i][j];
    //     }
    //     cout << endl;
    // }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[0][i] == map[m - 1][j] && map[0][i] != 1) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;

#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif

    return 0;
}