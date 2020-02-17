#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int n;
    cin >> n;
    cin.ignore();
    vector<int> temp(n);
    for (int i = 0; i < n; i++) {
        cin >> temp[i];
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int num = temp[i];
        if (num == 1) {
            continue;
        }
        if (num == 2) {
            sum++;
            continue;
        }
        for (int i = 2; i < num; i++) {
            if (num % i == 0) {
                sum--;
                break;
            }
        }
        sum++;
    }

    cout << sum << endl;

#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif

    return 0;
}