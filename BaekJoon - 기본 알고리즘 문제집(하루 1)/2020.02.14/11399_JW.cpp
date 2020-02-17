#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b){
    return b < a;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int n;
    cin >> n;
    vector<int> input(n);
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    sort(input.begin(), input.end(), compare);
    int index = 1;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += index++ * input[i];
    }

    cout << sum << endl;
    

#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif

    return 0;
}