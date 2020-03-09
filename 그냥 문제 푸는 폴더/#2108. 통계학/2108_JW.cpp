#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

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
    int max = -987654321, min = 987654321;
    long long sum = 0;
    vector<pair<int, int>> counting(9000, make_pair(0, 0));
    vector<int> input(n);
    for (int i = 0; i < n; i++) {
        cin >> input[i];
        counting[input[i] + 4000].first++;
        counting[input[i] + 4000].second = input[i];
        sum += input[i];
        if (max < input[i])
            max = input[i];
        if (min > input[i])
            min = input[i];
    }
    cout << round((long double)sum / n) << endl;
    sort(input.begin(), input.end());
    cout << input[input.size() / 2] << endl;
    sort(counting.begin(), counting.end(), compare);
    auto x = counting.end() - 1;
    while((*x).first == (*(x - 1)).first) x--;
    cout << (x + 1 == counting.end() ? (*x).second : (*(x + 1)).second) << endl;
    cout << max - min << endl;

#ifdef LOCAL
    fclose(stdin);
#endif

    return 0;
}