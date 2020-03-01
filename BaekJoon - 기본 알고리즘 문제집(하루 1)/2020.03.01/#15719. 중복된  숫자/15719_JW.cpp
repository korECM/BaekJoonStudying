#include <string.h>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    unsigned long long n;
    cin >> n;
    int input;
    unsigned long long sum = 0;
    unsigned long long rSum = n % 2 ? n * ((n - 1) / 2) : (n / 2) * (n - 1);
    for (int i = 0; i < n; i++) {
        cin >> input;
        sum += input;
    }
    cout << sum - rSum << endl;

#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif

    return 0;
}