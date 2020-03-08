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

    long long a, b, v;
    cin >> a >> b >> v;
    cout << (int)ceill((long double)(v - a) / (a - b)) + 1 << endl;

#ifdef LOCAL
    fclose(stdin);
#endif

    return 0;
}