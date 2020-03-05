#include <string.h>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define MAX 10001
#define MOD 10007

int mem[MAX][10];

int _solve(int n, int k) {
    if (n == 0)
        return 1;
    int& ret = mem[n][k];
    if (ret != -1)
        return ret;
    int sum = 0;
    for (int i = k; i <= 9; i++) {
        sum += _solve(n - 1, i);
        sum %= MOD;
    }
    return ret = sum;
}

int solve(int n) {
    int sum = 0;
    for (int i = 0; i <= 9; i++) {
        sum += _solve(n - 1, i);
        sum %= MOD;
    }
    return sum;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    int n;
    cin >> n;
    memset(mem, -1, sizeof(mem));
    cout << solve(n) << endl;

#ifdef LOCAL
    fclose(stdin);
#endif

    return 0;
}