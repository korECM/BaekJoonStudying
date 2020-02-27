#include <string.h>
#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, l;
    cin >> n >> l;
    vector<int> input(n);
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }
    deque<pair<int, int>> temp;
    for (int i = 0; i < n; i++) {
        while (!temp.empty() && temp.front().second <= i - l)
            temp.pop_front();
        while (!temp.empty() && temp.back().first > input[i])
            temp.pop_back();
        temp.push_back(make_pair(input[i], i));
        cout << temp.front().first << " ";
    }
    cout << endl;

#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif

    return 0;
}