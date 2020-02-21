#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef struct F {
    long long num;
    long long answer;
} f;

int check(int n);
f m[501] = {
    0,
};
f fac(int n) {
    if (n <= 1) {
        return m[n];
    }
    if (!m[n - 1].num) {
        m[n - 1] = fac(n - 1);
    }
    f newData;
    newData.num = m[n - 1].num * n;
    int temp = check(newData.num);
    newData.answer = m[n - 1].answer + temp;
    newData.num %= (int)(pow(10, temp + 3));
    newData.num /= (int)(pow(10, temp));
    m[n] = newData;
    return newData;
}

int check(int temp) {
    int sum = 0;
    while (temp % 10 == 0) {
        if (!temp) {
            break;
        }
        sum++;
        temp /= 10;
    }
    return sum;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    m[0].num = 1;
    m[0].answer = 0;
    m[1].num = 1;
    m[0].answer = 0;

    cout << fac(n).answer << endl;

#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif

    return 0;
}