#include <string.h>

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int n, a, b;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    vector<pair<int, int>> data;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        data.push_back({a - 1, b - 1});
    }

    sort(data.begin(), data.end());

    vector<int> raw;
    int count = 0;
    raw.push_back(-1);

    for (auto x : data) {
        if (x.second > raw.back()) {
            raw.push_back(x.second);
            count++;
        } else {
            auto y = lower_bound(raw.begin(), raw.end(), x.second);
            *y = x.second;
        }
    }

    cout << n - count << endl;

#ifdef LOCAL
    fclose(stdin);
#endif

    return 0;
}