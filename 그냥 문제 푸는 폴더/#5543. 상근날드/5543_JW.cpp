#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include <cmath>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;

    cout << min(a, min(b, c)) + min(d, e) - 50 << endl;

#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif

    return 0;
}