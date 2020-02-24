#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int n;
int countNum = 0;

void find(vector<vector<int>>& map,vector<vector<bool>>& visited, int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= n) {
        return;
    }
    if (map[y][x] != -1) {
        return;
    }
    if(visited[y][x]){
        return;
    }
    map[y][x] = countNum;
    visited[y][x] = true;
    find(map, visited, x - 1, y);
    find(map, visited, x + 1, y);
    find(map, visited, x, y + 1);
    find(map, visited, x, y - 1);
}

void solve(vector<vector<int>>& map, vector<vector<bool>>& visited) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == -1) {
                countNum++;
                find(map, visited, j, i);
            }
        }
    }
}

bool compare(int a, int b){
    return a < b;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    cin >> n;
    cin.ignore();
    vector<vector<int>> map(n, vector<int>(n));
    vector<vector<bool>> visited(n, vector<bool>(n));
    string input;
    for (int i = 0; i < n; i++) {
        cin >> input;
        for (int j = 0; j < n; j++) {
            map[i][j] = input[j] - '0';
            map[i][j] *= -1;
        }
        cin.ignore();
    }
    solve(map, visited);
    vector<int> countVector(countNum + 1, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // cout << map[i][j];
            countVector[map[i][j]]++;
        }
        // cout << endl;
    }
    sort(countVector.begin() + 1, countVector.end(), compare);
    cout << countNum << endl;
    for (int i = 1; i <= countNum; i++)
    {
        cout << countVector[i] << endl;
    }
    
    

#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif

    return 0;
}