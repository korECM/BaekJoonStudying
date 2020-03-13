#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include <cmath>

using namespace std;

int main() {
#ifdef LOCAL
    // freopen("input.txt", "r", stdin);
#endif

    int e, s, m;
    cin >> e >> s >> m;
    int oe = 1, os = 1, om = 1;
    int count = 1;
    while (e != oe || s != os || m != om) {
        oe = ++oe == 16 ? 1 : oe;
        os = ++os == 29 ? 1 : os;
        om = ++om == 20 ? 1 : om;
        count++;
    }
    cout << count << endl;

#ifdef LOCAL
    fclose(stdin);
#endif

    return 0;
}