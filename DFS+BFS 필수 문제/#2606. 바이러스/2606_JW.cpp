#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include <cmath>

using namespace std;

class Graph {
   public:
    int size;
    vector<vector<int>> node;
    bool visited[101];
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

    void _dfs(int start, int& count) {
        if (!visited[start]) {
            visited[start] = true;
            count++;
            for (auto x : node[start]) {
                _dfs(x, count);
            }
        }
    }

    int dfs(int start) {
        fill(&visited[0], &visited[100] + 1, false);
        int count = -1;
        _dfs(start, count);
        return count;
    }
};

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    int n, m;
    int from, to;
    cin >> n >> m;
    Graph g(n);
    for (int i = 0; i < m; i++) {
        cin >> from >> to;
        g.addEdge(from, to);
    }

    cout << g.dfs(1) << endl;

#ifdef LOCAL
    fclose(stdin);
#endif

    return 0;
}