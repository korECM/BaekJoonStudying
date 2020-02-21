#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int n;
    cin >> n;
    int sum = 1;
    if(n == 0){
        cout << 1 << endl;
        return 0;
    }
    while(n != 1){
        sum = sum * n;
        n--;
    }
    cout << sum << endl;

#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif

    return 0;
}