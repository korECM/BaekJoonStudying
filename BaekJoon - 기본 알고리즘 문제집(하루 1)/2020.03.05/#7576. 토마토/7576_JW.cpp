#include <string.h>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;
vector<pair<int, int>> done;
queue<pair<int, int>> task;
queue<pair<int, int>> task2;
int n, m;
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

int fulledCount = 0;

int solve(vector<vector<int>>& map) {
    int count = 0;
    while (true) {
        if (fulledCount == m * n)
            return count;
        count++;
        while (!task.empty()) {
            int x = task.front().first;
            int y = task.front().second;
            task.pop();
            for (int i = 0; i < 4; i++) {
                int cx = x + dx[i];
                int cy = y + dy[i];
                if (cx < 0 || cy < 0 || cx >= m || cy >= n)
                    continue;
                if (map[cy][cx] != 0)
                    continue;
                map[cy][cx] = 1;
                fulledCount++;
                task2.push(make_pair(cx, cy));
            }
        }

        // cout << endl;
        // for (int ii = 0; ii < n; ii++) {
        //     for (int jj = 0; jj < m; jj++) {
        //         cout << map[ii][jj] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;

        if (fulledCount == m * n)
            return count;
        count++;
        while (!task2.empty()) {
            int x = task2.front().first;
            int y = task2.front().second;
            task2.pop();
            for (int i = 0; i < 4; i++) {
                int cx = x + dx[i];
                int cy = y + dy[i];
                if (cx < 0 || cy < 0 || cx >= m || cy >= n)
                    continue;
                if (map[cy][cx] != 0)
                    continue;
                map[cy][cx] = 1;
                fulledCount++;
                task.push(make_pair(cx, cy));
            }
        }
        if (task.empty())
            return -1;
    }
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    cin >> m >> n;
    vector<vector<int>> map(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 1)
                task.push(make_pair(j, i));
            if (map[i][j] != 0)
                fulledCount++;
        }
    }

    cout << solve(map) << endl;

#ifdef LOCAL
    fclose(stdin);
#endif

    return 0;
}