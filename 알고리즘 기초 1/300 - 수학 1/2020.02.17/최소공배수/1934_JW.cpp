#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

long long lcm(long long a, long long b) {
    return a * (b / gcd(a, b));
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int n, a, b;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        cin.ignore();
        cout << lcm(a, b) << endl;
    }

#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif

    return 0;
}