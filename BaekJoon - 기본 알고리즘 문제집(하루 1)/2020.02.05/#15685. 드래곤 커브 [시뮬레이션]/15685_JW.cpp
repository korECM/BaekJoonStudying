#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef struct Point {
    int x;
    int y;
    int direction;
} point;

// 방향에 따른 점 이동
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, -1, 0, 1};

// 90도 회전
void rotation(point& p) {
    p.direction = (p.direction + 1) % 4;
}

// 범위 검사하고 맵에 점 추가하는 메소드
void mapAdd(vector<vector<int>>& map, int x, int y) {
    if (x < 0 || y < 0 || x > 100 | y > 100) {
        return;
    }
    map[y][x]++;
}

point draw(vector<vector<int>>& map,
           vector<point>& trace,
           point p,
           int direction,
           int generation) {

               // 0세대의 경우 그냥 그림
    if (generation == 0) {
        mapAdd(map, p.x, p.y);
        p.x += dx[p.direction];
        p.y += dy[p.direction];
        // 커브를 그리면서 지나온 자취를 trace에 저장
        point t = {p.x, p.y, p.direction};
        trace.push_back(t);
        mapAdd(map, p.x, p.y);
        return p;
    }
    // 0세대가 아닌 경우 우선 (generation - 1) 세대를 그림
    p = draw(map, trace, p, direction, generation - 1);

    // 이후 이를 끝점을 기준으로 90도 회전해서 다시 그려야하는데 여기에서 스택을 이용함
    // (generation - 1) 세대를 그리면서 지나온 자취를 90도 회전시켜서 역으로 그려나간다

    // 이렇게 회전시켜서 그려나가는 자취 또한 저장해야 하므로 원본 유지를 위해 복사본 생성
    vector<point> temp(trace.begin(), trace.end());

    // 모든 자취를 90도 회전
    for (int i = 0; i < temp.size(); i++) {
        rotation(temp[i]);
    }
    // 회전시킨 자취를 하나하나 그려나감
    while (!temp.empty()) {
        // 자취에서 좌표는 중요하지 않으므로 방향만 추출
        point pp = temp.back();
        temp.pop_back();
        // 우선 점을 그리고
        mapAdd(map, p.x, p.y);
        // 자취에 기록된 방향(이미 회전 됨)으로 그려나감
        p.x += dx[pp.direction];
        p.y += dy[pp.direction];
        mapAdd(map, p.x, p.y);
        // 이렇게 새로 지나온 길 또한 자취에 저장
        point t = {p.x, p.y, pp.direction};
        trace.push_back(t);
    }
    return p;
}

int main() {
    vector<vector<int>> map(101, vector<int>(101, 0));
    string t;
    int n;
    cin >> n;
    getline(cin, t);
    for (int i = 0; i < n; i++) {
        int x, y, dir, g;
        scanf("%d %d %d %d", &x, &y, &dir, &g);
        getchar();
        vector<point> trace;
        point p = {x, y, dir};
        draw(map, trace, p, dir, g);
    }

    // 정사각형 개수 개산
    int count = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (map[i][j] > 0) {
                if (map[i][j + 1] > 0 && map[i + 1][j] > 0 &&
                    map[i + 1][j + 1] > 0) {
                    count++;
                }
            }
        }
    }
    cout << count << endl;

    // 아래는 그리는 코드
    // for (int y = 0; y < 10; y++) {
    //     for (int x = 0; x < 10; x++) {
    //         cout << (map[y][x] > 0 ? '1' : '0') << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}