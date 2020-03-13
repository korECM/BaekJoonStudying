#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int m, n, k;
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};
vector<vector<bool>> visited(51, vector<bool>(51));

void bfs(vector<vector<bool>>& map, int x, int y) {
    visited[y][x] = true;
    for (int i = 0; i < 4; i++) {
        int cx = x + dx[i];
        int cy = y + dy[i];
        if (cx < 0 || cy < 0 || cx >= m || cy >= n)
            continue;
        if (!visited[cy][cx] && map[cy][cx])
            bfs(map, cx, cy);
    }
}

int solve(vector<vector<bool>>& map) {
    fill(visited.begin(), visited.end(), vector<bool>(51));
    int c = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] && !visited[i][j]) {
                bfs(map, j, i);
                c++;
            }
        }
    }
    return c;
}

int main() {
#ifdef LOCAL
    freopen("input2.txt", "r", stdin);
#endif

    int c;
    cin >> c;
    for (int caseNum = 0; caseNum < c; caseNum++) {
        cin >> m >> n >> k;
        vector<vector<bool>> map(n, vector<bool>(m, false));
        for (int i = 0; i < k; i++) {
            int x, y;
            cin >> x >> y;
            map[y][x] = true;
        }
        cout << solve(map) << endl;
    }

#ifdef LOCAL
    fclose(stdin);
#endif

    return 0;
}