#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    long long input;
    cin >> input;
    int n, temp;
    cin >> n;

    string result("");
    while (input) {
        temp = input % n;
        if (temp >= 10) {
            temp += 7;
        }
        temp += '0';
        result += temp;
        input /= n;
    }

    reverse(result.begin(), result.end());

    cout << result << endl;

#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif

    return 0;
}