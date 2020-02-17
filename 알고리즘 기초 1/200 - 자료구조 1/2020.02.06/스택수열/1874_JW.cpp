#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    int num;
    int count = 0;
    string result;
    vector<int> s;
    count = 0;
    for (int i = 0; i < n; i++) {
        cin >> num;
        getchar();
        if (num > count) {
            while (num != count) {
                count++;
                s.push_back(count);
                result.append("+\n");
            }
            s.pop_back();
            result.append("-\n");
        } else if (num < count) {
            if (s.back() == num) {
                s.pop_back();
                result.append("-\n");
            }
        } else {
            s.pop_back();
            result.append("-\n");
        }
    }
    if (s.empty()) {
        cout << result << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}