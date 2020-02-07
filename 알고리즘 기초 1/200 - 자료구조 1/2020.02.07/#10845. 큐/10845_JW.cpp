#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int main() {
    int n;
    cin >> n;
    // getchar();
    queue<int> queue;
    char temp[100];
    int k;
    for (int i = 0; i < n; i++) {
        scanf("%s", temp);
        if (strcmp(temp, "push") == 0) {
            scanf(" %d", &k);
            queue.push(k);
        } else if (strcmp(temp, "pop") == 0) {
            if (queue.empty()) {
                cout << -1 << endl;
            } else {
                cout << queue.front() << endl;
                queue.pop();
            }
        } else if (strcmp(temp, "back") == 0) {
            if (queue.empty()) {
                cout << -1 << endl;
            } else {
                cout << queue.back() << endl;
            }
        } else if (strcmp(temp, "front") == 0) {
            if (queue.empty()) {
                cout << -1 << endl;
            } else {
                cout << queue.front() << endl;
            }
        } else if (strcmp(temp, "empty") == 0) {
            cout << queue.empty() << endl;
        } else if (strcmp(temp, "size") == 0) {
            cout << queue.size() << endl;
        }
    }

    return 0;
}