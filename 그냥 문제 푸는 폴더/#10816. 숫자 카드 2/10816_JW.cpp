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
    int n;
    cin >> n;
    vector<int> input(n);
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }
    sort(input.begin(), input.end(), compare);
    int m;
    int count = 0;
    cin >> m;
    for (int i = 0; i < m; i++) {
        count = 0;
        cin >> n;
        cout << upper_bound(input.begin(), input.end(), n) -
                    lower_bound(input.begin(), input.end(), n)
             << " ";
    }

#ifdef LOCAL
    fclose(stdin);
#endif

    return 0;
}