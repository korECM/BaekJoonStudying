#include <string.h>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long mem[100001][4];

long long _solve(int n, int num) {
    if (n < 0)
        return 0;
    if (n == 0)
        return 1;
    if (n <= 2)
        return n != num;

    int first = (num) % 3 + 1;
    int second = (num + 1) % 3 + 1;

    long long& firstM = mem[n - first][first];
    long long& secondM = mem[n - second][second];
    if (firstM == -1)
        firstM = _solve(n - first, first) % 1'000'000'009;
    if (secondM == -1)
        secondM = _solve(n - second, second) % 1'000'000'009;

    return (firstM + secondM) % 1'000'000'009;
}

long long solve(int n) {
    return _solve(n - 1, 1) % 1'000'000'009 + _solve(n - 2, 2) % 1'000'000'009 +
           _solve(n - 3, 3) % 1'000'000'009;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int c, n;
    cin >> c;
    memset(mem, -1, sizeof(mem));
    for (int caseNum = 0; caseNum < c; caseNum++) {
        cin >> n;
        cout << solve(n) % 1'000'000'009 << endl;
    }

#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif

    return 0;
}