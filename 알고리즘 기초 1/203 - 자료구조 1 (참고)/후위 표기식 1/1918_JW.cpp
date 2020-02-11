#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int priNum(char a){
    if(a == '(') return 0;
    if(a == '+' || a== '-') return 1;
    if(a == '*' || a == '/') return 2;
}

bool pri(char a, char b) {
    // if(a == '('){
    //     return false;
    // }
    // if (a == '*' || a == '/') {
    //     return true;
    // }
    // if (a == '+' || b == '-') {
    //     if (b == '+' || b == '-' || b == '(') {
    //         return true;
    //     }
    //     return false;
    // }
    // return false;
    return (priNum(a) >= priNum(b));
}

int main() {
#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
#endif

    stack<char> temp;

    string input;
    getline(cin, input);
    int i = 0;

    for (int i = 0; i < input.length(); i++) {
        if (input[i] == '(') {
            temp.push('(');
        } else if ('A' <= input[i] && input[i] <= 'Z') {
            cout << input[i];
        } else if (input[i] == ')') {
            while (!temp.empty() && temp.top() != '(') {
                cout << temp.top();
                temp.pop();
            }
            if (!temp.empty()) {
                temp.pop();
            }
        } else {
            while (!temp.empty() && pri(temp.top(), input[i])) {
                if (temp.top() != '(') {
                    cout << temp.top();
                }
                temp.pop();
            }
            temp.push(input[i]);
        }
    }
    // printf("\nENd\n");
    while (!temp.empty()) {
        cout << temp.top();
        temp.pop();
    }
    cout << endl;

#ifndef ONLINE_JUDGE
    // fclose(stdin);
#endif

    return 0;
}