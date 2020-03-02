#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int n, m;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    string input;
    cin.ignore();
    vector<vector<char>> map(n, vector<char>(m));
    vector<vector<short>> dist(n, vector<short>(m, 30000));
    queue<pair<char, char>> q;
    for (int i = 0; i < n; i++) {
        cin >> input;
        for (int j = 0; j < m; j++) {
            map[i][j] = input[j] - '0';
        }
    }
    q.push(make_pair(0, 0));
    map[0][0] = 2;
    dist[0][0] = 1;

    while (!q.empty()) {
        char x = q.front().first;
        char y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            char cx = x + dx[i];
            char cy = y + dy[i];
            if (cx < 0 || cy < 0 || cx >= m || cy >= n || map[cy][cx] > 1 ||
                map[cy][cx] == 0)
                continue;
            dist[cy][cx] = min((short)(dist[y][x] + 1), dist[cy][cx]);
            map[cy][cx] = 2;
            q.push(make_pair(cx, cy));
        }
    }
    cout << dist[n - 1][m - 1] << endl;
    return 0;
}