#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include <cmath>
#include <deque>

using namespace std;


int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    int n;
    cin >> n;
    deque<int> q;
    for (int i = 1; i <= n; i++)
    {
        q.push_back(i);
    }
    while(q.size() != 1){
        q.pop_front();
        n = q.front();
        q.pop_front();
        q.push_back(n);   
    }
    cout << q.front() << endl;

#ifdef LOCAL
    fclose(stdin);
#endif

    return 0;
}