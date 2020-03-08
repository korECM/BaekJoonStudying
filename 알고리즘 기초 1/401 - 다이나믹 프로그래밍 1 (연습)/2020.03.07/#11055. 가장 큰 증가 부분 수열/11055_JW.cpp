#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include <cmath>

using namespace std;

vector<int> input(1000);
int map[1000];
int n;

int solve(int index) {
    if (index == n)
        return 0;
    int &ret = map[index];
    if(ret != -1) return ret;
    int maxi = input[index];

    for (int i = index + 1; i < n; i++) {
        if (input[i] > input[index]) {
            maxi = max(maxi, solve(i) + input[index]);
        }
    }

    return ret = maxi;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    memset(map, -1, sizeof(map));
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    int maxi = -1;
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, solve(i));
    }

    cout << maxi << endl;

#ifdef LOCAL
    fclose(stdin);
#endif

    return 0;
}