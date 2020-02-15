#include <algorithm>
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

    vector<string> temp;
    for (int i = 0; i < input.length(); i++) {
        temp.push_back(input.substr(i));
    }

    sort(temp.begin(), temp.end());

    for (int i = 0; i < temp.size(); i++) {
        cout << temp[i] << endl;
    }

#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif

    return 0;
}