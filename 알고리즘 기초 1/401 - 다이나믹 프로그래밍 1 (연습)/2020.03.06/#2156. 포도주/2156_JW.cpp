#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include <cmath>

using namespace std;

int mem[10001][3];

vector<int> map(10001);
int n;

int solve(int index, int count) {
    if (index == n)
        return 0;
    int& ret = mem[index][count];
    if (ret != -1)
        return ret;
    int maxi = 0;
    if (count != 0) {
        maxi = max(maxi, solve(index + 1, count - 1) + map[index]);
    }
    maxi = max(maxi, solve(index + 1, 2));
    return ret = maxi;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    memset(mem, -1, sizeof(mem));
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> map[i];
    }

    cout << solve(0, 2) << endl;

#ifdef LOCAL
    fclose(stdin);
#endif

    return 0;
}