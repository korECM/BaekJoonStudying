#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = n; i <= m; i++) {
        int num = i;
        if (num == 1) {
            continue;
        }
        if (num == 2) {
            printf("%d\n", i);
            continue;
        }
        if (num % 2 == 0) {
            continue;
        }
        bool flag = true;
        for (int j = 3; j <= sqrt(num); j += 2) {
            if (num % j == 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            printf("%d\n", i);
        }
    }
    // for (int i = 0; i < temp.size(); i++) {
    //     cout << temp[i] << endl;
    // }

#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif

    return 0;
}