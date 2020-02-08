#include <cmath>
#include <iostream>

using namespace std;

long long solve(long long n, long long r, long long c) {
    if (n == 2) {
        return 2 * r + c + 1;
    }

    if (r >= n / 2) {
        if (c >= n / 2) {  // 우아
            return (n / 2) * (n / 2) * 3 + solve(n / 2, r - n / 2, c - n / 2);
        } else {  // 왼아
            return (n / 2) * (n / 2) * 2 + solve(n / 2, r - n / 2, c);
        }
    } else {
        if (c >= n / 2) {  // 우위
            return (n / 2) * (n / 2) * 1 + solve(n / 2, r, c - n / 2);
        } else {  // 왼위
            return solve(n / 2, r, c);
        }
    }
}

int main() {
    long long n, r, c;
    cin >> n >> r >> c;

    cout << solve(pow(2, n), r, c) - 1 << endl;

    return 0;
}