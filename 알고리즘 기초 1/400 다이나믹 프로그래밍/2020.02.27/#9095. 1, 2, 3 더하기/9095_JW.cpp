#include <string.h>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int mem[11];

int solve(int n) {
    if (n < 0)
        return 0;
    if(n == 0)
        return 1;
    if (n == 1)
        return 1;

    int& ret = mem[n];
    if (ret != -1)
        return ret;
    return ret = solve(n - 1) + solve(n - 2) + solve(n - 3);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int n, temp;
    cin >> n;
    memset(mem, -1, sizeof(mem));
    for (int i = 0; i < n; i++) {
        cin >> temp;
        cout << solve(temp) << endl;
    }

#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif

    return 0;
}