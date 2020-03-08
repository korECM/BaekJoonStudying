#include <iostream>
#include <vector>

using namespace std;

int n, m;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    int from, to, cost;
    cin >> n >> m;
    vector<vector<int>> input(n, vector<int>(n, 987654321));
    for (int i = 0; i < m; i++) {
        cin >> from >> to >> cost;
        input[from - 1][to - 1] = min(input[from - 1][to - 1], cost);
    }
    for (int i = 0; i < n; i++) {
        input[i][i] = 0;
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (input[i][j] > input[i][k] + input[k][j]) {
                    input[i][j] = input[i][k] + input[k][j];
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << (input[i][j] != 987654321 ?  input[i][j] : 0) << " ";
        }
        cout << endl;
    }

#ifdef LOCAL
    fclose(stdin);
#endif

    return 0;
}