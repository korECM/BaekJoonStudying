#include <string.h>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long mem[101][10];

long long _solve(int n, int index) {
    if (index < 0 || index > 9)
        return 0;
    if (n == 0)
        return 1;
    long long sum = 0;
    if (index != 9) {
        long long& ret2 = mem[n - 1][index + 1];
        if (ret2 == -1)
            ret2 = (_solve(n - 1, index + 1) % 1'000'000'000);
        sum += ret2;
        sum %= 1'000'000'000;
    }
    if (index != 0) {
        long long& ret1 = mem[n - 1][index - 1];
        if (ret1 == -1)
            ret1 = (_solve(n - 1, index - 1) % 1'000'000'000);
        sum += ret1;
        sum %= 1'000'000'000;
    }

    return sum;
}

long long solve(int n) {
    long long sum = 0;
    for (int i = 1; i < 10; i++) {
        sum += _solve(n - 1, i);
        sum %= 1'000'000'000;
    }
    return sum;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int n;
    cin >> n;
    memset(mem, -1, sizeof(mem));
    cout << solve(n) << endl;

#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif

    return 0;
}