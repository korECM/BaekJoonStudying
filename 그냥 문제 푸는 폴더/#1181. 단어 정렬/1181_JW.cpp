#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include <cmath>

using namespace std;

bool compare(string a, string b) {
    if (a.length() == b.length()) {
        return a < b;
    }
    return a.length() < b.length();
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    vector<string> input(n);
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }
    sort(input.begin(), input.end(), compare);
    input.erase(unique(input.begin(), input.end()), input.end());
    for (auto x : input) {
        cout << x << "\n";
    }

#ifdef LOCAL
    fclose(stdin);
#endif

    return 0;
}