#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include <cmath>

using namespace std;

vector<int> map(1001);
int mem[1001];
int n;

int solve(int index) {
    int& cache = mem[index + 1];
    int maxi = 1;
    if (cache != -1)
        return cache;
    for (int i = index + 1; i < n; i++) {
        if (index == -1 || map[index] > map[i])
            maxi = max(maxi, solve(i) + 1);
    }

    return cache = maxi;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    cin >> n;
    memset(mem, -1, sizeof(mem));
    for (int i = 0; i < n; i++) {
        cin >> map[i];
    }

    cout << solve(-1) - 1 << endl;

#ifdef LOCAL
    fclose(stdin);
#endif

    return 0;
}