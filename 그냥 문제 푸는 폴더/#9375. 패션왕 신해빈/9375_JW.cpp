#include <string.h>

#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int c, n;
    cin >> c;
    for (int caseNum = 0; caseNum < c; caseNum++) {
        string a, b;
        multimap<string, string> list;
        vector<string> keys;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a >> b;
            if (list.count(b) == 0)
                keys.push_back(b);
            list.insert(pair<string, string>(b, a));
        }
        long long result = 1;

        for (int i = 0; i < keys.size(); i++) {
            result *= (list.count(keys[i]) + 1);
        }
        cout << result - 1 << endl;
    }

#ifdef LOCAL
    fclose(stdin);
#endif

    return 0;
}