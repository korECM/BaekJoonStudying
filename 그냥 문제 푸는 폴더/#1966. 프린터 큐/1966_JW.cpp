#include <algorithm>
#include <deque>
#include <iostream>

using namespace std;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    int c;
    cin >> c;
    for (int caseNum = 0; caseNum < c; caseNum++) {
        int n, m, temp;
        cin >> n >> m;
        deque<pair<int, int>> task;
        for (int i = 0; i < n; i++) {
            cin >> temp;
            task.push_front({temp, i});
        }
        int count = 0;
        while (!task.empty()) {
            count++;
            while (true) {
                int t = task.back().first;
                if (count_if(task.begin(), task.end(),
                             [t](pair<int, int> elem) {
                                 return elem.first > t;
                             }) == 0) {
                    break;
                }
                task.push_front(task.back());
                task.pop_back();
            }
            if (task.back().second == m) {
                cout << count << endl;
                break;
            }
            task.pop_back();
        }
    }

#ifdef LOCAL
    fclose(stdin);
#endif

    return 0;
}