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

    vector<int> num;
    bool flag = true;
    int i = input.length() - 1;
    for (; i >= 2; i -= 3) {
        int a = input[i] - '0';
        int b = input[i - 1] - '0';
        int c = input[i - 2] - '0';
        num.push_back(c * 4 + b * 2 + a);
        if (i == 2) {
            flag = false;
        }
    }
    if (flag) {
        if (i == 1) {
            cout << ((input[0] - '0') * 2 + input[1] - '0');
        } else {
            cout << input[0];
        }
    }
    while (!num.empty()) {
        cout << num.back();
        num.pop_back();
    }
    cout << endl;

#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif

    return 0;
}