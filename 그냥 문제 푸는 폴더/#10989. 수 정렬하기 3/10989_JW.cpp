#include <iostream>
#include <vector>

using namespace std;

vector<short> countNum(10'001, 0);

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    short temp;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> temp;
        countNum[temp]++;
    }
    for (int i = 1; i <= 10'001; i++) {
        for (int j = 0; j < countNum[i]; j++) {
            cout << i << "\n";
        }
    }

#ifdef LOCAL
    fclose(stdin);
#endif

    return 0;
}