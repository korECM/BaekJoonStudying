#include <string.h>

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int get(double x, double y) {
    return floor(y / x * 1000) / 10;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    while (true) {
        double x, y;
        cin >> x >> y;
        if (cin.eof()) {
            break;
        }
        int z = get(x, y);
        if (z >= 99) {
            cout << -1 << endl;
            continue;
        }
        long long l = 0;
        long long r = 2000000000;
        long long mid;
        while (l <= r) {
            mid = (l + r) / 2;
            if (l == mid - 1 || r == mid + 1)
                break;
            int t = get(x + mid, y + mid);
            // cout << l << " " << mid << " " << r << " " << z << " " << t << endl;
            if (z < t)
                r = mid + 1;
            else
                l = mid - 1;
        }
        while (true) {
            mid = (l + r) / 2;
            int t = get(x + mid, y + mid);
            // cout << l << " " << mid << " " << r << " " << z << " " << t << endl;
            if (z < t)
                break;
            else
                l++;
        }

        cout << mid << endl;
    }

#ifdef LOCAL
    fclose(stdin);
#endif

    return 0;
}