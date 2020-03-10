#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    long long n, m;
    cin >> n >> m;
    vector<long long> input(n);
    for (long long i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    sort(input.begin(), input.end(), [](long long a, long long b) { return a > b;});
    long long height = input.front();
    int index = 0;
    long long sum = 0;
    while(sum < m){
        height--;
        while(input[index + 1] > height){
            index++;
        }
        sum += (index + 1);
        // cout << "Height : " << height << " SUm : " << sum << endl;
    }
    cout << height << endl;

#ifdef LOCAL
    fclose(stdin);
#endif

    return 0;
}