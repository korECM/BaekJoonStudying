#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int A, B, C;
    cin >> A >> B >> C;
    cout << (A + B) % C << endl;
    cout << (A % C + B % C) % C << endl;
    cout << (A * B) % C << endl;
    cout << (A % C * B % C) % C << endl;

#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif

    return 0;
}