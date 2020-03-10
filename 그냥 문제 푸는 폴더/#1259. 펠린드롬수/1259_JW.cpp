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

    string temp;
    while (cin >> temp, temp != "0") {
        int length = temp.length();
        bool flag = true;
        for (int i = 0; i < length / 2; i++) {
            if (temp[i] != temp[length - 1 - i]) {
                flag = false;
                cout << "no" << endl;
                break;
            }
        }
        if (flag) {
            cout << "yes" << endl;
        }
    }

#ifdef LOCAL
    fclose(stdin);
#endif

    return 0;
}