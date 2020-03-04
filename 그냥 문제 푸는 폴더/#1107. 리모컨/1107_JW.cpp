#include <iostream>
#include <string.h>

using namespace std;

bool buttons[10];

pair<bool, int> checkAvaliable(int temp) {
    int count = 0;
    if (temp == 0)
        return make_pair(buttons[0], 1);
    while (temp) {
        count++;
        if (!buttons[temp % 10]) {
            return make_pair(false, 0);
        }
        temp /= 10;
    }
    return make_pair(true, count);
}

int main() {
    int n, m, temp;
    cin >> n >> m;
    memset(buttons, 1, sizeof(buttons));
    for (int i = 0; i < m; i++) {
        cin >> temp;
        buttons[temp] = false;
    }
    int minimum = abs(n - 100);
    pair<bool, int> result;
    for (int i = 0; i < 1'000'001; i++) {
        if (result = checkAvaliable(i), result.first) {
            minimum = min(minimum, abs(i - n) + result.second);
        }
    }
    cout << minimum << endl;
    return 0;
}