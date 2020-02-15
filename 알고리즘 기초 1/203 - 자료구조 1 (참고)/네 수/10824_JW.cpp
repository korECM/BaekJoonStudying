#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    long long a, b, c, d;
    cin >> a >> b >> c >> d;

    cout << (long long)((a * pow(10,to_string(b).length())+ b) + (c * pow(10,to_string(d).length())+ d)) << endl;

#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif

    return 0;
}