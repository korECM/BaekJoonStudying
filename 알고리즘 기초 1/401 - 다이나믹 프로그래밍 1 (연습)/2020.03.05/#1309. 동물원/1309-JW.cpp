#include <string.h>
#include <iostream>
using namespace std;
#define MAX 100001
#define MOD 9901

int mem[MAX][3];

// 0 빈거
// 1 왼
// 2 오른
int solve(int n, int c) {
    int& ret = mem[n][c];
    if (ret != -1)
        return ret;
    if (c == 1)
        return ret = (solve(n - 1, 0) + solve(n - 1, 2)) % MOD;
    if (c == 2)
        return ret = (solve(n - 1, 0) + solve(n - 1, 1)) % MOD;
    return ret = (solve(n - 1, 0) + solve(n - 1, 1) + solve(n - 1, 2)) % MOD;
}

int main() {
    int n;
    cin >> n;
    memset(mem, -1, sizeof(mem));
    mem[1][0] = 1;
    mem[1][1] = 1;
    mem[1][2] = 1;
    cout << (solve(n, 0) + solve(n, 1) + solve(n, 2)) % MOD << endl;
    return 0;
}