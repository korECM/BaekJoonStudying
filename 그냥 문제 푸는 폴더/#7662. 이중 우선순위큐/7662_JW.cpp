#include <iostream>
#include <vector>
#include <queue>



using namespace std;


int main() {




	int c;
	cin >> c;
	for (int caseNum = 0; caseNum < c; caseNum++) {
		int k;
		cin >> k;
		vector<bool> valid(k, false);
		priority_queue<pair<int, int>> max;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min;
		char ch;
		long long temp;
		for (int i = 0; i < k; i++)
		{
			cin >> ch >> temp;
			if (ch == 'I') {
				max.push({ temp, i });
				min.push({ temp, i });
			}
			else {
				while (!max.empty() && valid[max.top().second]) max.pop();
				while (!min.empty() && valid[min.top().second]) min.pop();
				if (temp == 1 && !max.empty()) {
					int index = max.top().second;
					max.pop();
					valid[index] = true;
				}
				else if(temp == -1 && !min.empty()){
					int index = min.top().second;
					min.pop();
					valid[index] = true;
				}
			}
		}
		while (!max.empty() && valid[max.top().second]) max.pop();
		while (!min.empty() && valid[min.top().second]) min.pop();
		if (max.empty()) cout << "EMPTY" << endl;
		else cout << max.top().first << " " << min.top().first << endl;
	}

	return 0;
}