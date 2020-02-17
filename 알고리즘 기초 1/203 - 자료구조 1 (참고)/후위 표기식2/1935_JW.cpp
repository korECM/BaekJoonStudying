#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    // freopen("./input.txt", "r", stdin);
#endif

    int n;
    cin >> n;
    cin.ignore();
    string input;
    stack<double> temp;
    vector<int> v(n);
    getline(cin, input);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    // cout << "Length : " << input.length() << endl;
    for (int i = 0; i < input.length(); i++) {
        char c = input[i];
        if (c == '+' || c == '-' || c == '/' || c == '*') {
            if (!temp.empty()) {
                double temp2 = temp.top();
                temp.pop();
                double temp1 = temp.top();
                temp.pop();
                if (c == '+') {
                    temp.push(temp1 + temp2);
                } else if (c == '-') {
                    temp.push(temp1 - temp2);
                } else if (c == '*') {
                    temp.push(temp1 * temp2);
                } else {
                    temp.push(temp1 / temp2);
                }
            }
        } else {
            // cout << "PUSH : " << c << endl;
            temp.push(v[c - 'A']);
        }
    }

    // cout << temp.top() << endl;
    printf("%.2f\n", temp.top());

#ifndef ONLINE_JUDGE
    // fclose(stdin);
#endif

    return 0;
}