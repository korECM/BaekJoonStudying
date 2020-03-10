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

    int n, m;
    cin >> n >> m;
    vector<string> input1(n);
    vector<string> input2(m);
    for (int i = 0; i < n; i++) {
        cin >> input1[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> input2[i];
    }
    sort(input1.begin(), input1.end());
    sort(input2.begin(), input2.end());
    // cout << endl;
    // cout << endl;
    // for (auto data : input1) {
    //     cout << data << "\n";
    // }
    // cout << endl;
    // cout << endl;
    // for (auto data : input2) {
    //     cout << data << "\n";
    // }

    vector<string> result(n + m + 100);
    auto x = set_intersection(input1.begin(), input1.end(), input2.begin(),
                              input2.end(), result.begin());
    result.erase(x, result.end());
    cout << result.size() << endl;
    for (auto data : result) {
        cout << data << "\n";
    }

#ifdef LOCAL
    fclose(stdin);
#endif

    return 0;
}