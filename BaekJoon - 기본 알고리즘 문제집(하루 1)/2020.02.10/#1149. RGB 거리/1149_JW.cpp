#include <iostream>
#include <vector>

using namespace std;

int mem[1000][3];

int solve(vector<vector<int>>& costs, int n, int color) {
    if (mem[n][color]) {
        return mem[n][color];
    }

    if (n == 0) {
        return costs[n][color];
    }

    int nextColor = (color + 1) % 3;
    int prevColor = (color + 2) % 3;

    if (mem[n - 1][prevColor] == 0) {
        mem[n - 1][prevColor] = solve(costs, n - 1, prevColor);
    }

    if (mem[n - 1][nextColor] == 0) {
        mem[n - 1][nextColor] = solve(costs, n - 1, nextColor);
    }
    mem[n][color] =
        min(mem[n - 1][nextColor], mem[n - 1][prevColor]) + costs[n][color];
    return mem[n][color];
}

int main() {
    int n;
    cin >> n;
    getchar();
    vector<vector<int>> costs(n, vector<int>(3));
    int r, g, b;
    for (int i = 0; i < n; i++) {
        cin >> r >> g >> b;
        getchar();
        costs[i][0] = r;
        costs[i][1] = g;
        costs[i][2] = b;
    }

    int result = min(min(solve(costs, n - 1, 0), solve(costs, n - 1, 1)),
                     solve(costs, n - 1, 2));
    cout << result << endl;

    return 0;
}