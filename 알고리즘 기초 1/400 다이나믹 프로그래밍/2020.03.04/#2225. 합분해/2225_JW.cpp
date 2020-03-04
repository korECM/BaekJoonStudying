#include <string.h>
#include <iostream>
using namespace std;

long long mem[201][201];

long long solve(int remain, int count) {
    if (count == 1)
        return 1;
    long long& ret = mem[remain][count];
    if (ret != -1)
        return ret;
    long long sum = 0;
    for (int i = 0; i <= remain; i++) {
        sum += solve(remain - i, count - 1);
        sum %= 1'000'000'000;
    }
    return ret = sum;
}

int main() {
    int n, k;
    cin >> n >> k;
    memset(mem, -1, sizeof(mem));
    cout << solve(n, k) << endl;
    return 0;
}
