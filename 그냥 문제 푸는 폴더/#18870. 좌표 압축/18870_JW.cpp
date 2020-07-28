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

    vector<int> data;
    vector<int> c;
    int n;
    cin >> n;
    data.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
    c = data;
    sort(c.begin(), c.end());
    c.erase(unique(c.begin(), c.end()), c.end());

    for (auto x : data) {
        printf("%ld ", lower_bound(c.begin(), c.end(), x) - c.begin());
    }
    cout << endl;

#ifdef LOCAL
    fclose(stdin);
#endif

    return 0;
}