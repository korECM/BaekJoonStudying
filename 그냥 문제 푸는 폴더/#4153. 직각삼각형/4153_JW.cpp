#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include <cmath>

using namespace std;

bool compare(int a, int b) {
    return a < b;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    vector<int> input(3);
    while (cin >> input[0] >> input[1] >> input[2],
           input[0] + input[1] + input[2]) {
        sort(input.begin(), input.end(), compare);
        int a = input[0];
        int b = input[1];
        int c = input[2];
        if ((long long)(c * c) == (long long)(a * a) + (long long)(b * b))
            cout << "right" << endl;
        else
            cout << "wrong" << endl;
    }

#ifdef LOCAL
    fclose(stdin);
#endif

    return 0;
}