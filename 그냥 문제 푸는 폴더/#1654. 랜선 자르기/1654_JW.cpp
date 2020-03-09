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

    int k, n;
    cin >> k >> n;
    vector<long long> input(k);
    for (int i = 0; i < k; i++) {
        cin >> input[i];
    }

    // sort(input.begin(), input.end());

    long long low = 1;
    long long high = *max_element(input.begin(), input.end()) + 1;
    long long mid = (low + high) / 2;
    while (low <= high && low != mid) {
        long long sum = 0;
        for (int i = 0; i < k; i++) {
            sum += input[i] / mid;
        }
        // cout << "cut : " << mid << " result : " << sum << endl;
        // cout << low << " " << mid << " " << high << endl;
        if (sum >= n) {
            low = mid;
        } else if (sum < n) {
            high = mid;
        } else {
            // break;
        }
        mid = (low + high) / 2;
    }

    cout << mid << endl;

#ifdef LOCAL
    fclose(stdin);
#endif

    return 0;
}