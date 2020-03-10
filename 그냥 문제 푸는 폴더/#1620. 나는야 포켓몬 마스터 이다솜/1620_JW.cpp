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

    map<int, string> data1;
    map<string, int> data2;
    string input;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> input;
        data1[i] = input;
        data2[input] = i + 1;
    }
    for (int i = 0; i < m; i++) {
        cin >> input;
        if ('0' <= input[0] && input[0] <= '9') {
            cout << data1[stoi(input) - 1] << "\n";
        } else {
            cout << data2[input] << "\n";
        }
    }

#ifdef LOCAL
    fclose(stdin);
#endif

    return 0;
}