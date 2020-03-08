#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include <cmath>

using namespace std;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    cout << (a * a + b * b + c * c + d * d + e * e) % 10 << endl;

#ifdef LOCAL
    fclose(stdin);
#endif

    return 0;
}