#include <iostream>
#include <vector>

using namespace std;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, temp;
    cin >> n >> m;
    vector<vector<int>> sum(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> temp;
            sum[i][j] =
                sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + temp;
        }
    }
    int x, y, xx, yy;
    for (int i = 0; i < m; i++) {
        cin >> y >> x >> yy >> xx;
        cout << sum[yy][xx] - sum[yy][x - 1] - sum[y - 1][xx] +
                    sum[y - 1][x - 1]
             << "\n";
    }

#ifdef LOCAL
    fclose(stdin);
#endif

    return 0;
}