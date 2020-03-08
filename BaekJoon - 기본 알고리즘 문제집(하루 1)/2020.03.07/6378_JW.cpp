#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include <cmath>

using namespace std;

string get(string input) {
    int sum = 0;
    for (auto x : input) {
        sum += x - '0';
    }
    return to_string(sum);
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    string input;
    while (true) {
        cin >> input;
        if (input[0] == '0')
            break;
        while (input = get(input), input.length() != 1) {
        }
        cout << input << endl;
    }

#ifdef LOCAL
    fclose(stdin);
#endif

    return 0;
}