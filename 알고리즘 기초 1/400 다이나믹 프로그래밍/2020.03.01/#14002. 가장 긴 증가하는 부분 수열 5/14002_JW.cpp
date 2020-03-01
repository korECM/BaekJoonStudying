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
    vector<int> input(n);
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }
    vector<int> dp(n, 1);
    vector<int> pointer(n, -1);
    int maxIndex = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (input[i] > input[j]) {
                if (dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    if (dp[maxIndex] < dp[i]) {
                        maxIndex = i;
                    }
                    pointer[i] = j;
                }
            }
        }
    }
    vector<int> result;
    int max = dp[maxIndex];
    while (pointer[maxIndex] != -1) {
        result.push_back(input[maxIndex]);
        maxIndex = pointer[maxIndex];
    }
    result.push_back(input[maxIndex]);
    cout << max << endl;
    while (!result.empty()) {
        cout << result.back() << " ";
        result.pop_back();
    }
    cout << endl;

#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif

    return 0;
}