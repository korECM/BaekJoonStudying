#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include <cmath>

using namespace std;

int first(int n) {
    if (!n)
        return 0;
    if (n == 1) {
        return 500;
    }
    n -= 1;
    if (n <= 2) {
        return 300;
    }
    n -= 2;
    if (n <= 3) {
        return 200;
    }
    n -= 3;
    if (n <= 4) {
        return 50;
    }
    n -= 4;
    if (n <= 5) {
        return 30;
    }
    n -= 5;
    if (n <= 6) {
        return 10;
    }
    n -= 6;
    return 0;
}
int second(int n) {
    if (!n)
        return 0;
    if (n == 1) {
        return 512;
    }
    n -= 1;
    if (n <= 2) {
        return 256;
    }
    n -= 2;
    if (n <= 4) {
        return 128;
    }
    n -= 4;
    if (n <= 8) {
        return 64;
    }
    n -= 8;
    if (n <= 16) {
        return 32;
    }
    n -= 16;
    return 0;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        int result = first(a) + second(b);
        cout << result;
        if (result)
            cout << "0000";
        cout << "\n";
    }

#ifdef LOCAL
    fclose(stdin);
#endif

    return 0;
}