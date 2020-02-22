#include <algorithm>
#include <deque>
#include <iostream>
#include <string>

using namespace std;

bool compare(int a, int b) {
    return b > a;
}

int cal(deque<int>& rest) {
    int sum = 0;
    for (auto x : rest) {
        sum += x;
    }
    return sum;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input1.txt", "r", stdin);
#endif

    int n;
    cin >> n;
    deque<int> rest;
    rest.push_back(64);
    int count = 0;
    while (cal(rest) > n) {
        sort(rest.begin(), rest.end(), compare);
        int temp = rest.front();
        rest.pop_front();
        rest.push_front(temp / 2);
        if (cal(rest) == n)
            break;
        if (cal(rest) < n) {
            rest.push_front(temp / 2);
        }
    }

    cout << rest.size() << endl;

#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif

    return 0;
}