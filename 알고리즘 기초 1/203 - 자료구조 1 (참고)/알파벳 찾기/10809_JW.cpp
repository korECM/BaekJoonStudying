#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> temp(26, -1);

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    string input;
    getline(cin, input);
    auto x = input.begin();
    while (x != input.end()) {
        if (temp[*x - 'a'] == -1) {
            temp[*x - 'a'] = (x - input.begin());
        }
        x++;
    }

    for (int i = 0; i < 26; i++) {
        if (i == 25) {
            cout << temp[i] << endl;
        } else {
            cout << temp[i] << " ";
        }
    }

#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif

    return 0;
}