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
    bool visited[1001];
    vector<vector<int>> node;
    Graph(int n) {
        size = n;
        for (int i = 0; i <= size; i++) {
            vector<int> temp;
            node.push_back(temp);
        }
    }

    void addEdge(int from, int to) {
        node[from].push_back(to);
        node[to].push_back(from);
    }

    void sortList() {
        for (auto &x : node) {
            sort(x.begin(), x.end());
        }
    }

    void _dfs(int start) {
        if (!visited[start]) {
            visited[start] = true;
            cout << start << " ";
            for (auto x : node[start]) {
                _dfs(x);
            }
        }
    }

    void dfs(int start) {
        fill(&visited[0], &visited[1000] + 1, false);
        _dfs(start);
        cout << "\n";
    }

    void bfs(int start) {
        queue<int> task;
        fill(&visited[0], &visited[1000] + 1, false);
        task.push(start);
        while (!task.empty()) {
            start = task.front();
            task.pop();
            if (!visited[start]) {
                visited[start] = true;
                cout << start << " ";
                for (auto x : node[start]) {
                    task.push(x);
                }
            }
        }
        cout << "\n";
    }
};

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    int n, m, v, from, to;
    cin >> n >> m >> v;
    Graph g(n);
    for (int i = 0; i < m; i++) {
        cin >> from >> to;
        g.addEdge(from, to);
    }
    g.sortList();
    g.dfs(v);
    g.bfs(v);

#ifdef LOCAL
    fclose(stdin);
#endif

    return 0;
}