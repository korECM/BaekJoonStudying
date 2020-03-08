#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first < b.first;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    int n;
    cin >> n;
    vector<pair<int, int>> input(n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &input[i].first, &input[i].second);
    }

    sort(input.begin(), input.end(), compare);

    for (auto x : input) {
        printf("%d %d\n", x.first, x.second);
    }

#ifdef LOCAL
    fclose(stdin);
#endif

    return 0;
}