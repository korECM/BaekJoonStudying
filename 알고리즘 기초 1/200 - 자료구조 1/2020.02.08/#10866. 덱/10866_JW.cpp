#include <iostream>
#include <deque>
#include <cstring>

using namespace std;

int main() {
    int n;
    cin >> n;
    // getchar();
    deque<int> deque;
    char temp[100];
    int k;
    for (int i = 0; i < n; i++) {
        scanf("%s", temp);
        if (strcmp(temp, "push_front") == 0) {
            scanf(" %d", &k);
            deque.push_front(k);
        } else if (strcmp(temp, "push_back") == 0) {
            scanf(" %d", &k);
            deque.push_back(k);
        }else if (strcmp(temp, "pop_front") == 0) {
            if (deque.empty()) {
                cout << -1 << endl;
            } else {
                cout << deque.front() << endl;
                deque.pop_front();
            }
        }else if (strcmp(temp, "pop_back") == 0) {
            if (deque.empty()) {
                cout << -1 << endl;
            } else {
                cout << deque.back() << endl;
                deque.pop_back();
            }
        }  else if (strcmp(temp, "back") == 0) {
            if (deque.empty()) {
                cout << -1 << endl;
            } else {
                cout << deque.back() << endl;
            }
        } else if (strcmp(temp, "front") == 0) {
            if (deque.empty()) {
                cout << -1 << endl;
            } else {
                cout << deque.front() << endl;
            }
        } else if (strcmp(temp, "empty") == 0) {
            cout << deque.empty() << endl;
        } else if (strcmp(temp, "size") == 0) {
            cout << deque.size() << endl;
        }
    }

    return 0;
}