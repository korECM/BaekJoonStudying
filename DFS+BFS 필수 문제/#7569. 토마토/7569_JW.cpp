#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;

int dx[6] = {0, 0, 1, -1, 0, 0};
int dy[6] = {1, -1, 0, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    int m, n, h;
    cin >> m >> n >> h;
    vector<vector<vector<int>>> map(h, vector<vector<int>>(n, vector<int>(m)));
    vector<vector<vector<bool>>> visited(
        h, vector<vector<bool>>(n, vector<bool>(m, false)));
    queue<tuple<int, int, int>> task;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                cin >> map[i][j][k];
                if (map[i][j][k] == 1) {
                    task.push(make_tuple(k, j, i));
                    visited[i][j][k] = true;
                }
                if (map[i][j][k] == -1)
                    visited[i][j][k] = true;
            }
        }
    }
    int x, y, z;
    int level = 0;
    while (!task.empty()) {
        int size = task.size();
        for (int i = 0; i < size; i++) {
            tie(x, y, z) = task.front();
            task.pop();
            for (int j = 0; j < 6; j++) {
                int cx = x + dx[j];
                int cy = y + dy[j];
                int cz = z + dz[j];
                if (cx < 0 || cy < 0 || cz < 0 || cx >= m || cy >= n || cz >= h)
                    continue;
                if (!visited[cz][cy][cx] && map[cz][cy][cx] != -1) {
                    task.push(make_tuple(cx, cy, cz));
                    visited[cz][cy][cx] = true;
                }
            }
        }
        level++;
    }
    bool flag = true;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (!visited[i][j][k]) {
                    flag = false;
                    break;
                }
            }
            if (!flag)
                break;
        }
        if (!flag)
            break;
    }
    if (flag) {
        cout << level - 1 << endl;
    } else {
        cout << "-1" << endl;
    }

#ifdef LOCAL
    fclose(stdin);
#endif

    return 0;
}