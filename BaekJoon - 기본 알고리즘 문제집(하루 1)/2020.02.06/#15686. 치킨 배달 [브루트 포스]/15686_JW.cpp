#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int INF = 987654321;
int n, m;
int chikenCount = 0;

int distance(int a, int b, int c, int d) {
    return abs(a - c) + abs(b - d);
}

int calOneDis(vector<vector<int>>& city, int x, int y) {
    int ret = INF;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (city[i][j] == 2) {
                ret = min(ret, distance(i, j, x, y));
            }
        }
    }
    return ret;
}

int calDis(vector<vector<int>>& city) {
    int ret = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (city[i][j] == 1) {
                ret += calOneDis(city, i, j);
            }
        }
    }
    return ret;
}

int solve(vector<vector<int>>& city, int willNotDelete, int x) {
    if (willNotDelete == chikenCount)
        return calDis(city);
    int ret = INF;
    for (int i = x; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (city[i][j] == 2) {
                city[i][j] = 0;
                chikenCount--;
                ret = min(solve(city, willNotDelete, i), ret);
                chikenCount++;
                city[i][j] = 2;
            }
        }
    }
    return ret;
}

int main() {
    string t;
    vector<vector<int>> city(50, vector<int>(50, 0));
    cin >> n >> m;
    getline(cin, t);
    for (int i = 0; i < n; i++) {
        getline(cin, t);
        for (int j = 0; j < n; j++) {
            city[i][j] = int(t[2 * j] - '0');
            if (city[i][j] == 2) {
                chikenCount++;
            }
        }
    }
    cout << solve(city, m, 0) << endl;

    return 0;
}