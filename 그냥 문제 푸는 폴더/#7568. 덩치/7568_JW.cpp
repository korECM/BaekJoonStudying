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
    int n, a, b;
    cin >> n;
    vector<pair<int, int>> input(n);
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        input[i] = {a, b};
    }
    for (int i = 0; i < n; i++) {
        int count = 1;
        pair<int, int> root = input[i];
        for (int j = 0; j < n; j++) {
            if (root.first < input[j].first && root.second < input[j].second)
                count++;
        }
        cout << count << " ";
    }
    cout << endl;

#ifdef LOCAL
    fclose(stdin);
#endif

    return 0;
}