#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int a, b;
    cin >> a >> b;
    cin.ignore();
    int n;
    cin >> n;
    cin.ignore();
    vector<int> input(n);
    vector<int> output;
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    long long temp = 0;
    for (int i = 0; i < n; i++)
    {
        temp += input[i] * (int)pow(a, input.size() -  1 - i);
    }
    while(temp){
        output.push_back(temp % b);
        temp /= b;
    }
    while(!output.empty()){
        cout << output.back();
        output.pop_back();
        if(!output.empty()){
            cout << " ";
        }
    }
    cout << endl;
    


#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif

    return 0;
}