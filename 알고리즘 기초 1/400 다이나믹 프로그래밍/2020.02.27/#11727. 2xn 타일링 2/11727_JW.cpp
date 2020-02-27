#include <string.h>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int mem[1001];

int solve(int n) {
    if (n == 1)
        return 1;
    int& ret = mem[n];
    if (ret != -1)
        return ret;
    return ret = (solve(n - 1) + solve(n - 2) * 2) % 10'007;
}

int main() {
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
// #endif

    int n;
    cin >> n;
    memset(mem, -1, sizeof(mem));
    mem[1] = 1;
    mem[2] = 3;
    cout << solve(n) << endl;

// #ifndef ONLINE_JUDGE
//     fclose(stdin);
// #endif

    return 0;
}