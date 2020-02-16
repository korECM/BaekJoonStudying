#include <iostream>
#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int lcm(int a, int b) {
    return a * (b / gcd(a, b));
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl << lcm(a, b) << endl;
#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif

    return 0;
}