#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int fre[1000001];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int n;
    cin >> n;
    vector<int> dataes(n);
    stack<int> s;
    stack<int> resultStack;
    string result("");

    for (int i = 0; i < n; i++) {
        cin >> dataes[i];
        fre[dataes[i]]++;
    }

    for (int i = n - 1; i >= 0; --i) {
        while (!s.empty() && fre[s.top()] <= fre[dataes[i]]) {
            s.pop();
        }
        if (s.empty()) {
            resultStack.push(-1);
        } else {
            resultStack.push(s.top());
        }
        s.push(dataes[i]);
    }
    while (!resultStack.empty()) {
        cout << resultStack.top();
        resultStack.pop();
        if (!resultStack.empty()) {
            cout << " ";
        }
    }

    cout << endl;

#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif

    return 0;
}