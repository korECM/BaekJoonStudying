#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    int storage = 0;
    char t;
    string s;
    getline(cin, s);
    for (int i = 0; i < n; i++) {
        storage = 0;
        int index = 0;
        getline(cin, s);
        while (true) {
            // cout << "asfafds         :           " << s << endl;
            if (s[index] == '(') {
                storage++;
            } else if (s[index] == ')') {
                storage--;
                if (storage < 0) {
                    break;
                }
            } else {
                break;
            }
            index++;
        }
        if (storage != 0) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }

    return 0;
}