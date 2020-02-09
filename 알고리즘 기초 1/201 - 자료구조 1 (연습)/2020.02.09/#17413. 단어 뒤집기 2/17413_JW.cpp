#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string input, result("");
    getline(cin, input);

    bool flag = false;
    stack<char> temp;

    for (int i = 0; i < input.length(); i++) {
        if (input[i] == '<') {
            flag = true;
            while (!temp.empty()) {
                result.append(string(1, temp.top()));
                temp.pop();
            }
            result.append(string(1, input[i]));
            continue;
        } else if (input[i] == '>') {
            flag = false;
            result.append(string(1, input[i]));
            continue;
        } else {
            if (!flag) {
                if (input[i] == ' ') {
                    while (!temp.empty()) {
                        result.append(string(1, temp.top()));
                        temp.pop();
                    }
                    result.append(" ");
                } else {
                    temp.push(input[i]);
                }
            } else {
                result.append(string(1, input[i]));
            }
        }
    }
    while (!temp.empty()) {
        result.append(string(1, temp.top()));
        temp.pop();
    }

    cout << result << endl;

    return 0;
}