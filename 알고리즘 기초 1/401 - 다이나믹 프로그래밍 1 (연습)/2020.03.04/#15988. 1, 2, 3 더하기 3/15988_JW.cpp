#include <string.h>
#include <iostream>

using namespace std;

long long mem[1000001];

long long solve(int n) {
    mem[1] = 1;
    mem[2] = 2;
    mem[3] = 4;
    for (int i = 4; i <= n; i++) {
        mem[i] = mem[i - 1] + mem[i - 2] + mem[i - 3];
        mem[i] %= 1'000'000'009;
    }
    return mem[n];
}

int main() {
    int n, temp;
    cin >> n;
    memset(mem, -1, sizeof(mem));
    for (int i = 0; i < n; i++) {
        cin >> temp;
        cout << solve(temp) << endl;
    }
    return 0;
}