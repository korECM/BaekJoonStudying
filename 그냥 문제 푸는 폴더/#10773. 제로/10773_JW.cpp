#include <string.h>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
#ifdef LOCAL
    freopen("input1.txt", "r", stdin);
#endif
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, temp;
    vector<int> inputs;
    cin >> n;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        if(temp == 0){
            sum -= inputs.back();
            inputs.pop_back();
        }else{
            inputs.push_back(temp);
            sum += temp;
        }
    }
    cout << sum << endl;

#ifdef LOCAL
    fclose(stdin);
#endif

    return 0;
}