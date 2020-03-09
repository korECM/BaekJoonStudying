#include <string.h>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    long long a, b, c;
    cin >> a >> b >> c;
    // (a + b * x) <= c * x
    if (b >= c) {
        cout << -1 << endl;
        return 0;
    }
    cout << (long long)ceil(((a + 0.001) / (c - b))) << endl;

#ifdef LOCAL
    fclose(stdin);
#endif

    return 0;
}