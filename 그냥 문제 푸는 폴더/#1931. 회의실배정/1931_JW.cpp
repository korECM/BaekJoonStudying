#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include <cmath>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    } else {
        return a.second < b.second;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int n, s, e;
    cin >> n;
    vector<pair<int, int>> input(n);
    for (int i = 0; i < n; i++) {
        cin >> s >> e;
        input[i] = make_pair(s, e);
    }

    sort(input.begin(), input.end(), compare);
    int befor = 0;
    int result = 0;
    for (int i = 0; i < n; i++) {
        if (befor <= input[i].first) {
            befor = input[i].second;
            result++;
        }
    }

    cout << result << endl;

#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif

    return 0;
}