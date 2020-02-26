#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool compare(int a, int b) {
    return a < b;
}

int main() {
    int n;
    cin >> n;
    vector<int> output;
    int index = 2;
    while (n != 1) {
        if (n % index == 0) {
            output.push_back(index);
            n /= index;
        } else {
            index++;
        }
    }
    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << endl;
    }
    return 0;
}