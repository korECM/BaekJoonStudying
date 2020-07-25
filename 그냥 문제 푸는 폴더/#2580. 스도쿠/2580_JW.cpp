#include <string.h>

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool check(vector<vector<int>>& board, int x, int y, int num) {
    for (int i = 0; i < 9; i++) {
        if (board[y][i] == num)
            return false;
        if (board[i][x] == num)
            return false;
    }

    int xNum = x / 3;
    int yNum = y / 3;

    for (int i = yNum * 3; i < (yNum + 1) * 3; i++) {
        for (int j = xNum * 3; j < (xNum + 1) * 3; j++) {
            if (board[i][j] == num)
                return false;
        }
    }
    return true;
}

bool solve(vector<vector<int>>& board) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] != 0)
                continue;
            for (int k = 1; k <= 9; k++) {
                if (check(board, j, i, k)) {
                    board[i][j] = k;
                    if (solve(board))
                        return true;
                    board[i][j] = 0;
                }
            }
            return false;
        }
    }
    return true;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    vector<vector<int>> board(9, vector<int>(9));

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
        }
    }

    solve(board);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

#ifdef LOCAL
    fclose(stdin);
#endif

    return 0;
}