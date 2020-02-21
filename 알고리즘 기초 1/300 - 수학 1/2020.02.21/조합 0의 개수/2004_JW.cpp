#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long findTwo(long long n) {
    int sum = 0;
    for (long long i = 2; n / i >= 1; i *= 2) {
        sum += n / i;
    }
    return sum;
}

long long findFive(long long n) {
    int sum = 0;
    for (long long i = 5; n / i >= 1; i *= 5) {
        sum += n / i;
    }
    return sum;
}
long long solve(long long n, long long m) {
    int two = 0;
    int five = 0;
    if (m > n / 2) {
        m = n - m;
    }
    two += findTwo(n);
    five += findFive(n);
    two -= findTwo(n - m);
    five -= findFive(n - m);
    two -= findTwo(m);
    five -= findFive(m);

    return min(two, five);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    long long n, m;
    cin >> n >> m;

    cout << solve(n, m) << endl;

#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif

    return 0;
}