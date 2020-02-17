#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main() {
#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
#endif

    string input;
    vector<int> num(26, 0);

    getline(cin, input);

    for (int i = 0; i < input.length(); i++)
    {
        num[input[i] - 'a']++;
    }

    for (int i = 0; i < num.size() - 1; i++)
    {
        cout << num[i] << " ";
    }
    cout << num[25] <<endl;
    

#ifndef ONLINE_JUDGE
    // fclose(stdin);
#endif

    return 0;
}