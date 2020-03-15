#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include <cmath>
#include <queue>

using namespace std;

class Graph {
   public:
    int size;
    vector<vector<int>> node;
    bool visited[102];
    Graph(int n) {
        size = n;
        for (int i = 0; i <= n; i++) {
            vector<int> temp;
            node.push_back(temp);
        }
    }
    void addEdge(int from, int to) {
        node[from].push_back(to);
        node[to].push_back(from);
    }

    int _dfs(int start, int to) {
        int c = 987654321;
        if (!visited[start]) {
            visited[start] = true;
            if (start == to) {
                return 1;
            }
            for (auto x : node[start]) {
                if (!visited[x]) {
                    c = min(c, _dfs(x, to));
                }
            }
        }
        return c + 1;
    }
    int dfs(int start, int to) {
        fill(visited, &visited[101] + 1, false);
        int count = 0;
        int mini = 987654321;
        for (auto x : node[start]) {
            count = _dfs(x, to);
            mini = min(mini, count);
        }
        return count >= 987654321 ? -1 : count;
    }
};

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    int n, a, b, m, from, to;
    cin >> n >> a >> b >> m;
    Graph g(n);
    for (int i = 0; i < m; i++) {
        cin >> from >> to;
        g.addEdge(from, to);
    }

    cout << g.dfs(a, b) << endl;

#ifdef LOCAL
    fclose(stdin);
#endif

    return 0;
}