#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    vector<bool> primes(1000001, true);

    for (int i = 2; i <= 1000000; i++) {
        for (int j = i * 2; j <= 1000000; j += i) {
            primes[j] = false;
        }
    }

    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        cin.ignore();
        int sum = 0;
        for(int i = 2; i <= temp / 2; i++){
            if(primes[i] && primes[temp - i]){
                sum++;
            }
        }
        cout << sum << endl;
    }

#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif

    return 0;
}