#include <string.h>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    int l, p;
    cin >> l >> p;

    int data[5];

    for (int i = 0; i < 5; i++) {
        cin >> data[i];
    }

    for (int i = 0; i < 5; i++) {
        cout << data[i] - l * p << " ";
    }
    cout << endl;

#ifdef LOCAL
    fclose(stdin);
#endif

    return 0;
}