#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;

int n, m;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input4.txt", "r", stdin);
#endif

    cin >> n >> m;
    vector<int> items;
    list<int> store;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        items.push_back(temp);
        store.push_back(i + 1);
    }
    auto x = store.begin();
    int sum = 0;
    for (int i = 0; i < m; i++) {
        auto temp = x;
        int count1 = 0;
        int count2 = 0;
        while (*x != items[i]) {
            x++;
            count1++;
            if (x == store.end()) {
                x = store.begin();
            }
        }
        x = temp;
        while (*x != items[i]) {
            if (x == store.begin()) {
                x = store.end();
            }
            x--;
            count2++;
        }
        x = store.erase(x);
        if (x == store.end()) {
            x = store.begin();
        }
        sum += min(count1, count2);
    }

    cout << sum << endl;

#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif

    return 0;
}