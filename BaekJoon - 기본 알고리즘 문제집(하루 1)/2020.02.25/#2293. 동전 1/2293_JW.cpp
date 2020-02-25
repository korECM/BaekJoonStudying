#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n, k;
    cin >> n >> k;
    cin.ignore();
    vector<int> data(k + 1, 0);
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        data[temp]++;
        for (int i = 1; i <= k; i++) {
            if (i + temp <= k) {
                data[i + temp] += data[i];
            }
        }
    }
    cout << data[k] << endl;

#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif

    return 0;
}