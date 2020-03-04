#include <string.h>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

bool visited[100001] = {
    false,
};

int solve(int n, int k) {
    queue<pair<int, int>> task;
    int count;
    int minimum = 987654321;
    task.push(make_pair(n, 0));
    while (!task.empty()) {
        n = task.front().first;
        count = task.front().second;
        task.pop();
        if (n < 0 || n > 100000 || visited[n])
            continue;
        visited[n] = true;
        if (n >= k) {
            minimum = min(minimum, count + n - k);
            continue;
        }
        task.push(make_pair(n - 1, count + 1));
        task.push(make_pair(n + 1, count + 1));
        task.push(make_pair(n * 2, count + 1));
    }
    return minimum;
}

int main() {
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    // #endif

    int n, k;
    cin >> n >> k;
    cout << solve(n, k) << endl;

    // #ifndef ONLINE_JUDGE
    //     fclose(stdin);
    // #endif

    return 0;
}