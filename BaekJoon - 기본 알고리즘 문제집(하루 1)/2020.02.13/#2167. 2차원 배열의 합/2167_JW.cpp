#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int n, m;
    cin >> n >> m;
    vector<vector<int>> input(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> mem(n + 1, vector<int>(m + 1, 0));
    cin.ignore();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> input[i][j];
            mem[i][j] =
                mem[i - 1][j] + mem[i][j - 1] - mem[i - 1][j - 1] + input[i][j];
        }
        cin.ignore();
    }
    int k;
    cin >> k;
    cin.ignore();
    int i, j, x, y;
    for (int index = 0; index < k; index++) {
        cin >> i >> j >> x >> y;
        cout << mem[x][y] - mem[x][j - 1] - mem[i - 1][y] + mem[i - 1][j - 1]
             << endl;
    }

#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif

    return 0;
}