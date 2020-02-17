#include <iostream>
#include <queue>
#include <stack>
#include <string>

using namespace std;

int main() {
    string input;
    cin >> input;

    int result = 0;

    stack<int> stick;

    for (int i = 0; i < input.length(); i++) {
        if (input[i] == '(') {
            if (i + 1 < input.length() && input[i + 1] == ')') {  // 레이저
                result += stick.size();
                i++;
            } else {  // 레이저가 아닌 경우
                stick.push(1);
                result++;
            }
        } else {                   // 막대 끝
            stick.pop();
        }
    }

    cout << result << endl;

    return 0;
}