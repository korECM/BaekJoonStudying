#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include <cmath>

using namespace std;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, temp, temp2;
    cin >> n >> m;
    // vector<int> input(n);
    vector<int> sum(n + 1);
    sum[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> temp;
        sum[i] = sum[i - 1] + temp;
    }
    for (int i = 0; i < m; i++) {
        cin >> temp >> temp2;
        cout << sum[temp2] - sum[temp - 1] << "\n";
    }

#ifdef LOCAL
    fclose(stdin);
#endif

    return 0;
}