#include <iostream>
#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int t, n;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++) {
        cin >> n;
        vector<int> input(n);
        for (int i = 0; i < n; i++) {
            cin >> input[i];
        }
        cin.ignore();
        long long sum = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                sum += gcd(input[i], input[j]);
            }
        }

        cout << sum << endl;
    }

#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif

    return 0;
}