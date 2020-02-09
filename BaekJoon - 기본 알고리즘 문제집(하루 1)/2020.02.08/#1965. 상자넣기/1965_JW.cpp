#include <iostream>
#include <vector>

using namespace std;

// int solve(vector<int> &boxes, int size,int start,int upper){

//     int index = -1;

//     int maximum = -987654321;

//     for(int i = start; i < size; i++){
//         if(boxes[i] > upper){
//             index = i;
//             break;
//         }
//     }
//     if(index == -1){
//         return 0;
//     }

//     maximum = max(solve(boxes, index + 1, upper), solve(boxes, index + 1, boxes[index]) + 1);

//     return maximum;

// }

int solveWithLIS(vector<int> &boxes){
    vector<int> temp;
    temp.push_back(-987654321);
    for(int i = 0; i < boxes.size(); i++){
        if(temp.back() >= boxes[i]){
            auto x = lower_bound(temp.begin(), temp.end(), boxes[i]);
            *x = boxes[i];
        }else{
            temp.push_back(boxes[i]);
        }
    }
    return temp.size() - 1;
}

int main() {
    int n;
    cin >> n;
    getchar();
    int temp;
    vector<int> boxes;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        boxes.push_back(temp);
    }

    // cout << solve(boxes, 0, 0)<< endl;
    cout << solveWithLIS(boxes) << endl;

    return 0;
}