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

    long long input;
    cin >> input;

    string s("");

    while (input) {
        if (input > 0) {
            s += (input % 2) + '0';
            input /= -2;
        } else {
            if (input % 2 == 0) {
                s += '0';
                input /= -2;
            } else {
                s += '1';
                input = abs(input) / 2 + 1;
            }
        }
    }

    reverse(s.begin(), s.end());

    cout << (s.length() ? s : "0") << endl;

#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif
    return 0;
}

// 1 5 13
// -6 -5 -4 -3 -2 -1 0 1 2 3 4 5
// 1110 1111 1100 1101 10 11 0 1 110 111 100 101 11010 11011 11000 11001