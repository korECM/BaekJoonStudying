
#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long gcd(long long a, long long b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input1.txt", "r", stdin);
#endif

    long long n, s;

    cin >> n >> s;
    cin.ignore();

    vector<long long> input(n + 1);

    for (long long i = 0; i < n; i++) {
        cin >> input[i];
        input[i] = abs(input[i] - s);
    }
    long long temp = input[0];
    for (int i = 1; i < n; i++)
    {
        temp = gcd(temp, input[i]);
    }
    cout << temp << endl;


#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif

    return 0;
}