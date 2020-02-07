#include <iostream>

using namespace std;

long long m[3000];

long long solve(int n) {
    if (n == 1) {
        return 1;
    }
    if (n == 2) {
        return 2;
    }
    if (m[n]) {
        return m[n];
    }
    m[n] = (solve(n - 1) + solve(n - 2)) % 10007;
    return m[n];
}

int main() {
    int n;
    cin >> n;
    cout << (solve(n)) << endl;

    return 0;
}