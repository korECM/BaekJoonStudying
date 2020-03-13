#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};
int nx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int ny[8] = {1, -1, 2, -2, 2, -2, 1, -1};
int k, w, h, temp;
bool visited[201][201][31];

int solve(vector<vector<bool>>& map) {
    queue<pair<pair<short, short>, pair<int, char>>> task;
    task.push({{0, 0}, {0, k}});
    int mini = 987654321;
    while (!task.empty()) {
        int x = task.front().first.first;
        int y = task.front().first.second;
        int count = task.front().second.first;
        int remain = task.front().second.second;
        visited[y][x][remain] = true;
        task.pop();
        for (int i = 0; i < 4; i++) {
            int cx = x + dx[i];
            int cy = y + dy[i];
            if (cx < 0 || cy < 0 || cx >= w || cy >= h)
                continue;
            if (visited[cy][cx][remain] || map[cy][cx])
                continue;
            if (cx == w - 1 && cy == h - 1) {
                mini = min(mini, count + 1);
                break;
            }
            task.push({{cx, cy}, {count + 1, remain}});
            visited[cy][cx][remain] = true;
        }
        for (int i = 0; i < 8 && remain > 0; i++) {
            int cx = x + nx[i];
            int cy = y + ny[i];
            if (cx < 0 || cy < 0 || cx >= w || cy >= h)
                continue;
            if (visited[cy][cx][remain - 1] || map[cy][cx])
                continue;
            if (cx == w - 1 && cy == h - 1) {
                mini = min(mini, count + 1);
                break;
            }
            task.push({{cx, cy}, {count + 1, remain - 1}});
            visited[cy][cx][remain - 1] = true;
        }
    }
    if (mini == 987654321)
        return -1;
    return mini;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    cin >> k >> w >> h;
    vector<vector<bool>> map(h, vector<bool>(w, false));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> temp;
            if (temp)
                map[i][j] = true;
        }
    }
    cout << solve(map) << endl;

#ifdef LOCAL
    fclose(stdin);
#endif

    return 0;
}