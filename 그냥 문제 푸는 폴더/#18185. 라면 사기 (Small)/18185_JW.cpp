#include <string.h>

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int n, minNum;
long long cost = 0;

void solve(vector<int>& input, int third, int fifth, int seventh, int index) {
    if (index >= n)
        return;
    int newFifth = min(third, input[index]);
    cost -= newFifth * 3;
    cost += newFifth * 5;
    input[index] -= newFifth;

    int newSeventh = min(fifth, input[index]);
    cost -= newSeventh * 5;
    cost += newSeventh * 7;
    input[index] -= newSeventh;

    int newThird = input[index];
    cost += newThird * 3;
    input[index] = 0;

    solve(input, newThird, newFifth, newSeventh, index + 1);
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    vector<int> input(n);
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    solve(input, 0, 0, 0, 0);

    cout << cost << endl;

#ifdef LOCAL
    fclose(stdin);
#endif

    return 0;
}