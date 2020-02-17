#include <iostream>
#include <string>
#include <vector>

using namespace std;

int xMax = -1;
int yMax = -1;
vector<vector<int>> mapX(302);
vector<vector<int>> mapY(302);

int solve(vector<vector<int>>& map, int x, int y, int count) {
    // cout << "X : " << x << " Y : " << y << " Count : " << count << endl;
    if (count <= 0) {
        // cout << "1 " << endl;
        return 0;
    }
    if (xMax < x || yMax < y) {
        // cout << "2" << endl;
        return 0;
    }
    int maximum = 0;
    if (xMax == x || y == yMax) {
        bool flag = true;
        for (int i = 0; i < mapX[x].size(); i++) {
            if (y < mapX[x][i] && count - (mapX[x][i] - y) > 0) {
                int k;
                flag = false;
                maximum = max(maximum, k = solve(map, x, mapX[x][i],
                                                 count - (mapX[x][i] - y)) +
                                           count);
                // cout << "solve : " << k << " + " << count - (mapX[x][i] - y)
                //      << endl;
            }
        }
        for (int i = 0; i < mapY[y].size(); i++) {
            if (x < mapY[y][i] && count - (mapY[y][i] - x) > 0) {
                flag = false;
                maximum = max(maximum, solve(map, mapY[y][i], y,
                                             count - (mapY[y][i] - x)) +
                                           count);
            }
        }
        if(flag){
            return count;
        }else{
            return maximum;
        }
    }

    bool flag = true;
    if (mapX[x].size() + mapY[y].size()) {
        // cout << "3 " << endl;
        //  << "x : " << mapX[x].size() << " y : " << mapY[y].size() << endl;
        // cout << "We Have a Candy!" << endl;
        for (int i = 0; i < mapX[x].size(); i++) {
            if (y < mapX[x][i] && count - (mapX[x][i] - y) > 0) {
                int k;
                flag = false;
                maximum = max(maximum, k = solve(map, x, mapX[x][i],
                                                 count - (mapX[x][i] - y)) +
                                           count);
                // cout << "solve : " << k << " + " << count - (mapX[x][i] - y)
                //      << endl;
            }
        }
        for (int i = 0; i < mapY[y].size(); i++) {
            if (x < mapY[y][i] && count - (mapY[y][i] - x) > 0) {
                flag = false;
                maximum = max(maximum, solve(map, mapY[y][i], y,
                                             count - (mapY[y][i] - x)) +
                                           count);
            }
        }
    }
    if (flag) {
        // if (map[y + 1][y + 1]) {
        //     // cout << "4 " << endl;
        //     maximum =
        //         max(maximum, solve(map, x + 1, y + 1, count - 2) + count -
        //         2);
        // } else {
        //     // cout << "5 " << endl;
        //     maximum = max(maximum, solve(map, x + 1, y + 1, count - 2));
        // }
        maximum = max(maximum, solve(map, x + 1, y + 1, count - 2));
    }
    return maximum;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int n, m;
    cin >> n >> m;
    cin.ignore();
    vector<vector<int>> map(302, vector<int>(302, 0));
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if (xMax < x)
            xMax = x;
        if (yMax < y)
            yMax = y;
        mapX[x].push_back(y);
        mapY[y].push_back(x);
        cin.ignore();
        map[y][x] = 1;
    }

    cout << solve(map, 0, 0, m) << endl;

#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif

    return 0;
}