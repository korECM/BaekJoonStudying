#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // ios_base ::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> dataes(n);
    stack<int> s;
    stack<int> resultStack;
    string result("");

    // getchar();
    for (int i = 0; i < n; i++) {
        cin >> dataes[i];
    }

    for (int i = n - 1; i >= 0; --i) {
        while (!s.empty() && s.top() <= dataes[i]) {
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

    // fclose(stdin);
    // fclose(stdout);

    return 0;
}