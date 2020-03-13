#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph {
   public:
    int size;
    vector<vector<int>> node;
    Graph(int n) {
        size = n;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            node.push_back(temp);
        }
    }

    void addEdge(int from, int to) { node[from].push_back(to); }

    bool dfs(int i, int j) {
        stack<int> task;
        vector<bool> visited(size, false);
        task.push(i);
        while (!task.empty()) {
            int next = task.top();
            task.pop();
            visited[next] = true;
            node[next];
            for (auto des : node[next]) {
                if (des == j)
                    return true;
                if (!visited[des])
                    task.push(des);
            }
        }
        return false;
    }
};

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    int n, temp;
    cin >> n;
    Graph g(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> temp;
            if (temp)
                g.addEdge(i, j);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << (g.dfs(i, j) ? 1 : 0) << " ";
        }
        cout << "\n";
    }

#ifdef LOCAL
    fclose(stdin);
#endif

    return 0;
}