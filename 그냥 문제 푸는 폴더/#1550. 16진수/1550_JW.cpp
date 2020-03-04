#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include <cmath>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    string a;
    int num;
    cin >> a;
    long long sum = 0;
    int count = a.length();
    for (auto x : a) {
        if (x >= 'A')
            num = x - 'A' + 10;
        else
            num = x - '0';
        sum += pow(16, --count) * num;
    }
    cout << sum << endl;

#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif

    return 0;
}