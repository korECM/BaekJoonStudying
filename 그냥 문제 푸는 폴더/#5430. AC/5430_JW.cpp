#include <algorithm>
#include <deque>
#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int c;
    cin >> c;
    string task, temp;
    regex number("[0-9]+");
    for (int caseNum = 0; caseNum < c; caseNum++) {
        cin >> task;
        cin.ignore();
        int n;
        cin >> n;
        deque<int> input(n);
        deque<int> input2(n);
        cin >> temp;
        sregex_iterator it(temp.begin(), temp.end(), number);
        sregex_iterator end;
        int index = 0;
        while (it != end) {
            smatch m = *it;
            input[index++] = stoi(m.str(0));
            ++it;
        }
        bool flag = false;
        for (auto x : task) {
            if (x == 'R') {
                flag = !flag;
            } else {
                if (input.empty()) {
                    cout << "error" << endl;
                    n = -1;
                    break;
                } else {
                    if (flag) {
                        input.pop_back();
                    } else {
                        input.pop_front();
                    }
                    n--;
                }
            }
        }
        if (n > -1) {
            cout << "[";
            if (flag) {
                for (int i = n - 1; i >= 1; i--) {
                    cout << input[i] << ',';
                }
                if (n > 0)
                    cout << input[0];
            } else {
                for (int i = 0; i < n - 1; i++) {
                    cout << input[i] << ',';
                }
                if (n > 0)
                    cout << input[n - 1];
            }
            cout << "]\n";
        }
    }

#ifdef LOCAL
    fclose(stdin);
#endif

    return 0;
}