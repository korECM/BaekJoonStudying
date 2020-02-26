#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int n, k;
    cin >> n >> k;
    vector<int> map(100001, 987654321);
    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        map[temp] = 1;
        for (int i = 1; i <= k; i++)
        {
            map[i + temp] = min(map[i + temp], map[i] + 1);
        }
    }
    
    if(map[k] != 987654321){
        cout << map[k] << endl;
    }else{
        cout << -1 << endl;
    }

#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif

    return 0;
}