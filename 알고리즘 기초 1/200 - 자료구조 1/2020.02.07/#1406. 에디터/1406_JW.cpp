#include <iostream>
#include <list>
#include <string>

using namespace std;

const int INPUT_STRING_SIZE = 100001;
const int STRING_SIZE = 600001;

int main() {
    int m;
    list<char> input;
    string t;
    char c;
    c = getchar();
    while (c != '\n') {
        input.push_back(c);
        c = getchar();
    }
    list<char>::iterator cursorIndex = input.end();
    list<char>::iterator temp;
    cin >> m;
    getline(cin, t);

    // 입력 받기 위까지

    for (int i = 0; i < m; i++) {
        getline(cin, t);
        switch (t[0]) {
            case 'L':
                // 맨 앞 아니면 앞으로 한칸 이동
                cursorIndex != input.begin() ? --cursorIndex : cursorIndex;
                break;
            case 'D':
                // 맨 뒤 아니면 뒤로 한칸 이동
                cursorIndex != input.end() ? ++cursorIndex : cursorIndex;
                break;
            case 'B':
                if (cursorIndex != input.begin()) {
                    temp = --cursorIndex;
                    cursorIndex = input.erase(temp);
                }
                break;
            case 'P':
                cursorIndex = input.insert(cursorIndex, t[2]);
                cursorIndex++;
                break;
        }
    }
    while (!input.empty()) {
        printf("%c", input.front());
        input.pop_front();
    }
    printf("\n");
    return 0;
}