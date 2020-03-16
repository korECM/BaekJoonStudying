#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include <cmath>

using namespace std;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    int n, temp;
    cin >> n;
    vector<int> input;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        if (input.empty())
            input.push_back(temp);
        else if (!input.empty() && input.back() < temp)
            input.push_back(temp);
        else {
            auto x = lower_bound(input.begin(), input.end(), temp);
            *x = temp;
        }
    }
    cout << input.size() << endl;

#ifdef LOCAL
    fclose(stdin);
#endif

    return 0;
}