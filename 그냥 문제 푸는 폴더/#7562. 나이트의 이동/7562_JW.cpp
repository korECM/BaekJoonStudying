#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n, c, fromX, fromY, toX, toY;
int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {1, -1, 2, -2, 2, -2, 1, -1};
int solve(int x, int y) {
    queue<pair<int, int>> task;
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    task.push({x, y});
    visited[y][x] = true;
    int level = -1;
    while (!task.empty()) {
        level++;
        int size = task.size();
        for (int j = 0; j < size; j++) {
            x = task.front().first;
            y = task.front().second;
            task.pop();
            if (x == toX && y == toY) {
                return level;
            }
            for (int i = 0; i < 8; i++) {
                int cx = x + dx[i];
                int cy = y + dy[i];
                if (cx < 0 || cy < 0 || cx >= n || cy >= n)
                    continue;
                if (!visited[cy][cx]) {
                    visited[cy][cx] = true;
                    task.push({cx, cy});
                }
            }
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    cin >> c;
    for (int caseNum = 0; caseNum < c; caseNum++) {
        cin >> n >> fromX >> fromY >> toX >> toY;
        cout << solve(fromX, fromY) << "\n";
    }

#ifdef LOCAL
    fclose(stdin);
#endif

    return 0;
}