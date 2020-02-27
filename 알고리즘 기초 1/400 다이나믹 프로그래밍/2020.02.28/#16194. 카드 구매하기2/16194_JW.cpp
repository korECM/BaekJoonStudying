#include <string.h>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n;

int mem[1001][10001];

int solve(vector<int>& input, int remain, int index) {
    if (index == 1)
        return remain * input[1];
    if (remain == 0)
        return 0;
    if (remain < 0)
        return 987654321;

    int& ret = mem[remain][index];
    if (ret != -1)
        return ret;

    int minimum = 987654321;
    minimum =
        min(minimum, solve(input, remain - index, index) + input[index]);
    minimum = min(minimum, solve(input, remain, index - 1));

    return ret = minimum;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input1.txt", "r", stdin);
#endif

    cin >> n;
    vector<int> input(n + 1);
    memset(mem, -1, sizeof(mem));
    for (int i = 1; i <= n; i++) {
        cin >> input[i];
    }

    cout << solve(input, n, n) << endl;

#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif

    return 0;
}