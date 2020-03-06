#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include <cmath>

using namespace std;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    string input;
    cin >> input;
    int length = input.length();
    for (int i = 0; i < length / 2; i++) {
        if (input[i] != input[length - i - 1]) {
            cout << 0 << endl;
            return 0;
        }
    }
    cout << 1 << endl;

#ifdef LOCAL
    fclose(stdin);
#endif

    return 0;
}