#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    string input;
    while (getline(cin, input), !(input.length() == 1 && input[0] == '.')) {
        stack<char> s;
        bool flag = true;
        for (auto x : input) {
            if (x == '(' || x == '[') {
                s.push(x);
            } else if (x == ')' || x == ']') {
                if (s.empty() || s.top() != (x == ')' ? '(' : '[')) {
                    flag = false;
                    break;
                }
                s.pop();
            }
        }
        if (flag && s.empty())
            cout << "yes" << endl;
        else {
            cout << "no" << endl;
        }
    }

#ifdef LOCAL
    fclose(stdin);
#endif

    return 0;
}