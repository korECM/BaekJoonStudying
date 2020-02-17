#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> stack;
    char temp[100];
    int k;
    for (int i = 0; i < n; i++) {
        scanf("%s", temp);
        if (strcmp(temp, "push") == 0) {
            scanf(" %d", &k);
            stack.push_back(k);
        } else if (strcmp(temp, "pop") == 0) {
            if (stack.empty()) {
                cout << -1 << endl;
            } else {
                cout << stack.back() << endl;
                stack.pop_back();
            }
        } else if (strcmp(temp, "top") == 0) {
            if (stack.empty()) {
                cout << -1 << endl;
            } else {
                cout << stack.back() << endl;
            }
        } else if (strcmp(temp, "empty") == 0) {
            cout << stack.empty() << endl;
        } else if (strcmp(temp, "size") == 0) {
            cout << stack.size() << endl;
        }
    }

    return 0;
}