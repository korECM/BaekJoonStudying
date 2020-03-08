#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include <cmath>
#include <queue>
#include <fstream>
#include <ctime>
#define GEN_NUM 15
#define CROSS 7
#define RAN 3

using namespace std;
int dx[8] = {1, 0, 0, -1, 1, 1, -1, -1};
int dy[8] = {0, 1, -1, 0, 1, -1, 1, -1};

bool _solve(vector<vector<int>>& map, vector<int> list, int x, int y) {
    queue<pair<pair<int, int>, vector<int>>> task;
    list.erase(list.begin(), list.begin() + 1);
    task.push(make_pair(make_pair(x, y), list));
    while (!task.empty()) {
        list = task.front().second;
        x = task.front().first.first;
        y = task.front().first.second;
        task.pop();
        for (int i = 0; i < 8; i++) {
            int cx = x + dx[i];
            int cy = y + dy[i];
            // cout << cx << " " << cy << endl;
            if (list.empty())
                break;
            if (cx < 0 || cy < 0 || cx >= 14 || cy >= 8)
                continue;
            if (map[cy][cx] != list.front())
                continue;
            // cout << "Find! " << list.front() << " " << cx << " " << cy <<
            // endl;
            list.erase(list.begin(), list.begin() + 1);
            task.push(make_pair(make_pair(cx, cy), list));
        }
        // cout << "asdfdsf " << list[0] << endl;
        if (list.empty())
            return true;
    }
    return false;
}

string solve(vector<vector<int>>& map) {
    string count = "1";
    while (true) {
        vector<int> nums;
        bool flag = false;
        for (int i = 0; i < count.length(); i++) {
            nums.push_back(count[i] - '0');
        }
        for (int j = 0; j < 8; j++) {
            for (int k = 0; k < 14; k++) {
                if (nums[0] == map[j][k]) {
                    if (_solve(map, nums, k, j)) {
                        count = to_string(stoi(count) + 1);
                        flag = true;
                        break;
                    }
                }
            }
            if (flag)
                break;
        }
        if (!flag)
            return count;
    }
    return count;
}
int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    // string test;
    srand(time(NULL));
    vector<pair<string, int>> g(GEN_NUM);
    for (int i = 0; i < GEN_NUM; i++) {
        g[i].first = "";
        for (int j = 0; j < 8 * 14; j++) {
            g[i].first += to_string(rand() % 10);
        }
        g[i].second = 0;
    }
    g[0].first =
        "7698124397088745600462955214527411788937731926365073422177049907698467"
        "445121860315366750388140182422993501287127";
    long long gen = 1;
    vector<vector<int>> map(8, vector<int>(14));
    while (true) {
        // cout << "GENERATION : " << gen++ << endl;
        for (int i = 0; i < GEN_NUM; i++) {
            string input = g[i].first;
            // cout << input << endl;
            auto x = input.begin();
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 14; j++) {
                    // map[i][j] = i + j;
                    map[i][j] = *x++ - '0';
                }
            }
            int score = stoi(solve(map)) - 1;
            g[i].second = score;
            if (score >= 650) {
                cout << score << "\n";
                // cout << endl;
                // for (int i = 0; i < 8; i++) {
                //     for (int j = 0; j < 14; j++) {
                //         cout << map[i][j];
                //     }
                //     cout << endl;
                // }
                // cout << endl;
            }
            if (score >= 700) {
                ofstream writeFile;
                writeFile.open(to_string(score) + ".txt");
                writeFile.write(input.c_str(), input.size());
                writeFile.close();
                cout << "\n" << input << "\n";
            }
            // if (score >= 1000) {
            //     cout << score << endl;
            //     cout << endl;
            //     for (int i = 0; i < 8; i++) {
            //         for (int j = 0; j < 14; j++) {
            //             cout << map[i][j];
            //         }
            //         cout << endl;
            //     }
            //     cout << endl;
            // }
            if (score > 8200) {
                cout << "===================" << endl;
                cout << score << endl;
                break;
            }
        }
        long double roulette[GEN_NUM];
        long long sum = 0;
        for (int i = 0; i < GEN_NUM; i++) {
            sum += g[i].second + 1;
        }
        for (int i = 0; i < GEN_NUM; i++) {
            roulette[i] = (long double)(g[i].second + 1) / sum * 100;
            if (i > 0)
                roulette[i] += roulette[i - 1];
        }

        vector<pair<string, int>> ng(GEN_NUM);
        string g1, g2;
        for (int i = 0; i < GEN_NUM - 1; i++) {
            int randomNum = rand() % 99 + 1;
            for (int j = 0; j < GEN_NUM; j++) {
                if (randomNum <= roulette[j]) {
                    g1 = g[i].first;
                    break;
                }
            }
            randomNum = rand() % 99 + 1;
            for (int j = 0; j < GEN_NUM; j++) {
                if (randomNum <= roulette[j]) {
                    g2 = g[i].first;
                    break;
                }
            }
            int anotherRandom = rand() % 10;
            if (true || anotherRandom > CROSS) {
                ng[i].first = (randomNum % 2 == 0 ? g1 : g2);
            } else {
                vector<int> temp(2);
                temp[0] = 0;
                for (int j = 1; j <= 1; j++) {
                    temp[j] = rand() % (8 * 14);
                }
                sort(temp.begin(), temp.end());
                ng[i].first = "";
                for (int j = 1; j <= 1; j++) {
                    randomNum = temp[j];
                    if (randomNum % 2 == 0) {
                        ng[i].first += g1.substr(temp[j - 1], randomNum);
                    } else {
                        ng[i].first += g2.substr(temp[j - 1], randomNum);
                    }
                }
                if (temp.back() % 2 == 0) {
                    ng[i].first += g1.substr(temp.back());
                } else {
                    ng[i].first += g2.substr(temp.back());
                }
            }
        }

        int maxi = 0;
        for (int i = 1; i < GEN_NUM; i++) {
            if (g[maxi].second < g[i].second)
                maxi = i;
        }
        // cout << "MAX : " << g[maxi].second << endl;
        ng[GEN_NUM - 1].first = g[maxi].first;
        for (int j = 0; j < GEN_NUM; j++) {
            for (int i = 0; i < 8 * 14; i++) {
                int randomNum = rand() % 100;
                if (randomNum <= RAN) {
                    ng[j].first[i] = to_string(rand() % 10)[0];
                }
            }
        }

        for (int i = 0; i < GEN_NUM; i++) {
            g[i] = ng[i];
        }
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 14; j++) {
            cout << map[i][j];
        }
        cout << endl;
    }
    // cout << stoi(solve()) - 1 << endl;

#ifdef LOCAL
    fclose(stdin);
#endif

    return 0;
}
