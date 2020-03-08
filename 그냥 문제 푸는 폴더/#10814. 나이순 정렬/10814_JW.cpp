#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include <cmath>

using namespace std;

bool compare(pair<pair<int, string>, int> a, pair<pair<int, string>, int> b) {
    if (a.first.first == b.first.first)
        return a.second < b.second;
    return a.first.first < b.first.first;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    int n, temp;
    string str;
    cin >> n;
    vector<pair<pair<int, string>, int>> input(n);
    vector<pair<int, int>> ord(n);
    for (int i = 0; i < n; i++) {
        cin >> temp >> str;
        input[i] = make_pair(make_pair(temp, str), i);
    }

    sort(input.begin(), input.end(), compare);

    for (auto x : input) {
        cout << x.first.first << " " << x.first.second << "\n";
    }

#ifdef LOCAL
    fclose(stdin);
#endif

    return 0;
}