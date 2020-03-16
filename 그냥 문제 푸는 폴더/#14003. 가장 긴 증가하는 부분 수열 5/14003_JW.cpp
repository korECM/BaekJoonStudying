#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include <cmath>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, temp;
    cin >> n;
    vector<pair<int, int>> input;
    vector<int> in(n);
    vector<int> backt(n + 1, -1);
    input.push_back({-1'000'000'001, -1});
    for (int i = 0; i < n; i++) {
        cin >> temp;
        in[i] = temp;
        if (!input.empty() && input.back().first < temp) {
            backt[i] = input.back().second;
            input.push_back({temp, i});
        } else {
            auto x = lower_bound(input.begin(), input.end(), make_pair(temp, i),
                                 comp);
            backt[i] = (x - 1)->second;
            *x = {temp, i};
        }
    }
    cout << input.size() - 1 << endl;
    vector<int> result;
    for (auto i = input.back().second; i >= 0; i = backt[i]) {
        result.push_back(in[i]);
    }
    reverse(result.begin(), result.end());
    for (auto x : result) {
        cout << x << " ";
    }
    cout << endl;

    // cout << input.size() << endl;

#ifdef LOCAL
    fclose(stdin);
#endif

    return 0;
}