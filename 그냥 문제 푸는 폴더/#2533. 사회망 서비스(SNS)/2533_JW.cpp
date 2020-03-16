#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

vector<int> edge[1'000'001], child[1'000'001];
bool visited[1'000'001] = {
    false,
};

int dp[1'000'001][2];

void dfs(int start) {
    visited[start] = true;
    for (auto x : edge[start]) {
        if (!visited[x]) {
            child[start].push_back(x);
            dfs(x);
        }
    }
}

int SNS(int curr, bool pe) {
    int& ret = dp[curr][pe];
    if (ret != -1)
        return ret;
    int pick = 1;
    int notPick = 987654321;
    for (auto x : child[curr]) {
        pick += SNS(x, true);
    }
    if (pe) {
        notPick = 0;
        for (auto x : child[curr]) {
            notPick += SNS(x, false);
        }
    }
    return ret = min(notPick, pick);
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    int n, from, to;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> from >> to;
        from--;
        to--;
        edge[from].push_back(to);
        edge[to].push_back(from);
    }
    dfs(0);
    memset(dp, -1, sizeof(dp));
    cout << SNS(0, true) << endl;

#ifdef LOCAL
    fclose(stdin);
#endif

    return 0;
}