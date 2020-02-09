#include <deque>
#include <iostream>
#include <string>

using namespace std;

int n, m;

deque<int>::iterator cursor;

void moveOneStep(deque<int>& data) {
    if (cursor == data.end()) {
        cursor = data.begin();
    }
    cursor++;
    if (cursor == data.end()) {
        cursor = data.begin();
    }
}

void move(deque<int>& data, int step) {
    for (int i = 0; i < step; i++) {
        moveOneStep(data);
    }
}

int main() {
    cin >> n >> m;

    deque<int> data;

    for (int i = 0; i < n; i++) {
        data.push_back(i + 1);
    }

    cursor = data.begin();

    string result;

    while (!data.empty()) {
        move(data, m - 1);
        result.append(to_string(*cursor) + ", ");
        cursor = data.erase(cursor);
    }

    result = result.substr(0, result.length() - 2);

    cout << "<" << result << ">" << endl;

    return 0;
}
