#include <iostream>
#include <vector>

using namespace std;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    int n, k;
    vector<int> result;
    cin >> n >> k;
    vector<int> input(n);
    for (int i = 1; i <= n; i++) {
        input[i - 1] = i;
    }
    auto x = input.begin();
    int count = 0;
    cout << "<";
    while (input.size()) {
        while (count < k - 1) {
            x++;
            if (x == input.end())
                x = input.begin();
            count++;
        }
        count = 0;
        result.push_back(*x);
        x = input.erase(x);
        if (x == input.end())
            x = input.begin();
    }
    for (int i = 0; i < result.size() - 1; i++) {
        cout << result[i] << ", ";
    }
    cout << input[0] << ">" << endl;

#ifdef LOCAL
    fclose(stdin);
#endif

    return 0;
}