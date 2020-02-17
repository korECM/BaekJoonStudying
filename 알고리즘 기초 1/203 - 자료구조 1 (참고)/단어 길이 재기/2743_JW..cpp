
#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    string input;
    getline(cin, input);
    cout << input.length() << endl;

#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif

    return 0;
}