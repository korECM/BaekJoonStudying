#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

vector<int> input(501);

long long normal[501];
long long doubleNormal[501];

long double getDistribution(int from, int to) {
    long long sum1 = 0, sum2 = 0;
    for (int i = from; i <= to; i++) {
        sum1 += input[i];
        sum2 += (long long)input[i] * (long long)input[i];
    }
    long double av1 = (long double)sum1 / (to - from + 1);
    long double av2 = (long double)sum2 / (to - from + 1);
    return av2 - av1 * av1;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    cout << setprecision(16);

    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    long double mini = 9.223372036854776e+18;
    for (int i = 0; i < n - k + 1; i++) {
        for (int j = k; j < n - i + 1; j++) {
            mini = min(mini, getDistribution(i, i + j - 1));
        }
    }
    cout << sqrt(mini) << endl;

#ifdef LOCAL
    fclose(stdin);
#endif

    return 0;
}