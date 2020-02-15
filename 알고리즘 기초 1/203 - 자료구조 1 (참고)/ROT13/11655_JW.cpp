#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    string input;
    getline(cin, input);
    for (int i = 0; i < input.length(); i++) {
        if ('a' <= input[i] && input[i] <= 'z') {
            if (input[i] >= 'a' + 13) {
                input[i] -= 26;
            }
            input[i] += 13;
        } else if ('A' <= input[i] && input[i] <= 'Z') {
            input[i] += 13;
            if (input[i] > 'Z') {
                input[i] -= 26;
            }
        }
    }

    cout << input << endl;

#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif

    return 0;
}