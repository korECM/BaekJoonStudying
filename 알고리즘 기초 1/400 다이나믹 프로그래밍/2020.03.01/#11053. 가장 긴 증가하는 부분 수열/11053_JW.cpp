#include <string.h>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int n;
    cin >> n;
    vector<int> temp;
    temp.push_back(-1);
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        if (temp.back() < input)
            temp.push_back(input);
        else {
            auto x = lower_bound(temp.begin(), temp.end(), input);
            *x = input;
        }
    }
    cout << temp.size() - 1 << endl;

#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif

    return 0;
}