#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    string input;
    cin >> input;

    for (auto x : input) {
        int temp = x - '0';
        int a = 0;
        int b = 0;
        int c = 0;
        c = temp % 2;
        temp /= 2;
        b = temp % 2;
        temp /= 2;
        a = temp % 2;
        //TODO: 이거 처음 숫자 0이면 출력 안되게 수정해야함
        cout << c << b << a;
    }
    cout << endl;

#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif

    return 0;
}