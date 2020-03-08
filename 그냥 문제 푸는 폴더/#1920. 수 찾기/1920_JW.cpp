#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include <cmath>

using namespace std;

bool compare(int a, int b) {
    return a < b;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n;
    vector<int> input(n);
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }
    sort(input.begin(), input.end(), compare);
    cin >> m;
    int temp;
    for (int i = 0; i < m; i++) {
        cin >> temp;
        cout << (temp == *lower_bound(input.begin(), input.end(), temp))
             << "\n";
    }

#ifdef LOCAL
    fclose(stdin);
#endif

    return 0;
}