#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    string input;
    cin >> input;
    int n, temp;
    cin >> n;
    long long result = 0;
    int index = 1;
    for(auto x : input){
        temp = x - '0';
        if(temp > 9){
            temp -= 7;
        }
        result += pow(n, input.length() - index) * temp;
        index++;
    }
    cout << result << endl;

#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif

    return 0;
}