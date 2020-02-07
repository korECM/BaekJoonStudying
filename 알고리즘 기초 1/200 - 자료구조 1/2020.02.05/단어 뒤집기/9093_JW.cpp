#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    string k;
    string result;
    vector<string> temp;
    int index = 0;
    int lindex;
    getline(cin, k);
    for (int i = 0; i < n; i++) {
        getline(cin, k);
        lindex = k.find(' ');
        while (lindex != string::npos) {
            // cout << "Index : " << index << " Li : " << lindex << endl;
            for (int j = index; j < lindex; j++) {
                temp.push_back(k.substr(j, 1));
            }
            k = k.substr(lindex + 1);
            for (int j = index; j < lindex; j++) {
                result.append(temp.back());
                temp.pop_back();
            }
            result.append(" ");
            lindex = k.find(' ');
        }
        for (int j = 0; j < k.length(); j++) {
            temp.push_back(k.substr(j, 1));
        }
        while(!temp.empty()){
            result.append(temp.back());
            temp.pop_back();
        }
        cout << result << endl;
        result.clear();
    }

    return 0;
}