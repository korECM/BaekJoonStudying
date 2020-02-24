#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    string input;
    cin >> input;

    bool flag = true;

    for (auto x : input) {
        int temp = x - '0';
        int a = 0;
        int b = 0;
        int c = 0;
        c = temp % 2;
        temp /= 2;
        b = temp % 2;
        temp /= 2;
        a = temp % 2;
        if (flag) {
            cout << (a * 100 + b * 10 + c);
            flag = false;
            continue;
        }
        cout << a << b << c;
    }
    cout << endl;

#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif

    return 0;
}