#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include <cmath>

using namespace std;
int mem[2][100001];
int map[2][100001];
int n;

int solve(int x, int y) {
    if (x >= n) {
        return 0;
    }
    int& ret = mem[y][x];
    if (ret != -1)
        return ret;
    // 안 고른 경우
    int maxi = max(solve(x + 1, 0), solve(x + 1, 1));

    // 고른 경우
    maxi = max(maxi, solve(x + 1, (y + 1) % 2) + map[y][x]);
    return ret = maxi;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    int c;
    cin >> c;
    for (int caseNum = 0; caseNum < c; caseNum++) {
        memset(mem, -1, sizeof(mem));
        cin >> n;
        for (int a = 0; a < 2; a++) {
            for (int i = 0; i < n; i++) {
                cin >> map[a][i];
            }
        }
        cout << max(solve(0, 0), solve(0, 1)) << endl;
    }

#ifdef LOCAL
    fclose(stdin);
#endif

    return 0;
}