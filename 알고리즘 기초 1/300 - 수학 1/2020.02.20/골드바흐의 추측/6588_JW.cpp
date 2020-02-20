#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MAX = 1000000;

vector<bool> primes(MAX + 1, true);
bool solve(int n, int& a, int& b) {
    for (int i = 2; i <= n / 2; i++) {
        if (primes[i] && primes[n - i]) {
            a = i;
            b = n - i;
            return true;
        }
    }
    return false;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    for (int i = 2; i <= MAX; i++) {
        for (int j = i * 2; j <= MAX; j += i) {
            primes[j] = false;
        }
    }

    int n;
    int a, b;
    while (scanf("%d", &n), n != 0) {
        if (solve(n, a, b)) {
            printf("%d = %d + %d\n", n, a, b);
        } else {
            printf("Goldbach's conjecture is wrong.\n");
        }
    }

#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif

    return 0;
}