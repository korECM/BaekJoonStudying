#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int n, m;
    cin >> n >> m;
    cin.ignore();
    vector<int> pay(n);
    long long max = -987654321;
    long long temp = 0;

    if (m == 0) {
        cout << 0 << endl;
        return 0;
    }

    for (int i = 0; i < m - 1; i++) {
        cin >> pay[i];
        temp += pay[i];
    }
    for (int i = m - 1; i < n; i++) {
        cin >> pay[i];
        temp += pay[i];
        if (temp > max) {
            max = temp;
        }
        temp -= pay[i - m + 1];
    }
    cout << max << endl;

#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif

    return 0;
}