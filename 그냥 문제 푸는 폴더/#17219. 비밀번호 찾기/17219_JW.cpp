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

    int a, b;
    string c, d;
    map<string, string> data;
    cin >> a >> b;

    for (int i = 0; i < a; i++) {
        cin >> c >> d;
        data[c] = d;
    }
    for (int i = 0; i < b; i++) {
        cin >> c;
        cout << data[c] << '\n';
    }

#ifdef LOCAL
    fclose(stdin);
#endif

    return 0;
}