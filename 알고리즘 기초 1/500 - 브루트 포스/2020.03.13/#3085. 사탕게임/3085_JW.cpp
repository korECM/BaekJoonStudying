#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include <cmath>

using namespace std;
int n;

int cal(vector<vector<char>>& map, int x, int y) {
    int result = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (map[y][i] == 'C')
            count++;
        else {
            result = max(result, count);
            count = 0;
        }
    }
    result = max(result, count);
    count = 0;
    for (int i = 0; i < n; i++) {
        if (map[i][x] == 'C')
            count++;
        else {
            result = max(result, count);
            count = 0;
        }
    }
    result = max(result, count);
    count = 0;
    for (int i = 0; i < n; i++) {
        if (map[y][i] == 'P')
            count++;
        else {
            result = max(result, count);
            count = 0;
        }
    }
    result = max(result, count);
    count = 0;
    for (int i = 0; i < n; i++) {
        if (map[i][x] == 'P')
            count++;
        else {
            result = max(result, count);
            count = 0;
        }
    }
    result = max(result, count);
    count = 0;
    for (int i = 0; i < n; i++) {
        if (map[y][i] == 'Z')
            count++;
        else {
            result = max(result, count);
            count = 0;
        }
    }
    result = max(result, count);
    count = 0;
    for (int i = 0; i < n; i++) {
        if (map[i][x] == 'Z')
            count++;
        else {
            result = max(result, count);
            count = 0;
        }
    }
    result = max(result, count);
    count = 0;
    for (int i = 0; i < n; i++) {
        if (map[y][i] == 'Y')
            count++;
        else {
            result = max(result, count);
            count = 0;
        }
    }
    result = max(result, count);
    count = 0;
    for (int i = 0; i < n; i++) {
        if (map[i][x] == 'Y')
            count++;
        else {
            result = max(result, count);
            count = 0;
        }
    }
    return result;
}

int solve(vector<vector<char>>& map) {
    int result = 0;
    for (int i = 0; i < n; i++) {
        result = max(result, cal(map, i, i));
    }
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if (x + 1 < n) {
                swap(map[y][x], map[y][x + 1]);
                result = max(result, cal(map, x, y));
                result = max(result, cal(map, x + 1, y));
                swap(map[y][x], map[y][x + 1]);
            }
            if (y + 1 < n) {
                swap(map[y][x], map[y + 1][x]);
                result = max(result, cal(map, x, y));
                result = max(result, cal(map, x, y + 1));
                swap(map[y][x], map[y + 1][x]);
            }
        }
    }
    return result;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    string temp;
    cin >> n;
    vector<vector<char>> map(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        cin >> temp;
        for (int j = 0; j < n; j++) {
            map[i][j] = temp[j];
        }
    }
    cout << solve(map) << endl;

#ifdef LOCAL
    fclose(stdin);
#endif

    return 0;
}