#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

int n, temp;
long double p[4];
vector<vector<bool>> visited(50, vector<bool>(50, false));
long double solve(int x, int y, int count) {
    if (visited[y][x])
        return 0;
    if (count >= n)
        return 1;
    long double pos = 0;
    visited[y][x] = true;
    if (!visited[y][x + 1])
        pos += p[0] * solve(x + 1, y, count + 1);
    if (!visited[y][x - 1])
        pos += p[1] * solve(x - 1, y, count + 1);
    if (!visited[y + 1][x])
        pos += p[2] * solve(x, y + 1, count + 1);
    if (!visited[y - 1][x])
        pos += p[3] * solve(x, y - 1, count + 1);
    visited[y][x] = false;
    // cout << count << " " << pos << endl;
    return pos;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    cin >> n;

    for (int i = 0; i < 4; i++) {
        cin >> temp;
        p[i] = (long double)temp / 100;
    }

    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    cout.precision(11);
    cout << fixed;
    cout << solve(25, 25, 0) << endl;

#ifdef LOCAL
    fclose(stdin);
#endif

    return 0;
}