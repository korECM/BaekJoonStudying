#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include <cmath>

using namespace std;
vector<int> input(1000);
int cache[1001][2];
int n;

int solve(int index, bool goUp) {
    int& ret = cache[index + 1][goUp];
    if (ret != -1)
        return ret;
    int maxi = 1;
    for (int i = index + 1; i < n; i++) {
        if (index == -1) {
            maxi = max(maxi, solve(i, true) + 1);
            maxi = max(maxi, solve(i, false) + 1);
        } else if (goUp && input[index] < input[i]) {
            maxi = max(maxi, solve(i, true) + 1);
            maxi = max(maxi, solve(i, false) + 1);
        } else if (!goUp && input[index] > input[i]) {
            maxi = max(maxi, solve(i, false) + 1);
        }
    }
    return ret = maxi;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    cin >> n;
    memset(cache, -1, sizeof(cache));
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    cout << solve(-1, true) - 1 << endl;

#ifdef LOCAL
    fclose(stdin);
#endif

    return 0;
}