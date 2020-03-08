#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include <cmath>

using namespace std;
vector<int> input(100'000);
int cache[100'000][2];
int n;

int solve(int index, bool canDelete) {
    if (index == n)
        return -987654321;
    int& ret = cache[index][canDelete];
    if (ret != -1)
        return ret;
    int maxi = input[index];
    if (canDelete) {
        maxi = max(maxi, solve(index + 1, false));
    }
    maxi = max(maxi, solve(index + 1, canDelete) + input[index]);
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

    int maxi = input[0];

    for (int i = 0; i < n; i++) {
        maxi = max(maxi, solve(i, n != 1));
    }
    cout << maxi << endl;

#ifdef LOCAL
    fclose(stdin);
#endif

    return 0;
}