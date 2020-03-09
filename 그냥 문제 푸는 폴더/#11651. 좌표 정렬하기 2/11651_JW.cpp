#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include <cmath>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
    return a.second == b.second ? a.first < b.first : a.second < b.second;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    int n, x, y;
    cin >> n;
    vector<pair<int, int>> input(n);
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        input[i] = {x, y};
    }
    sort(input.begin(), input.end(), compare);
    for(auto x : input){
        cout << x.first << " " << x.second << "\n";
    }
#ifdef LOCAL
    fclose(stdin);
#endif

    return 0;
}