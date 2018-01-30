#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;


int main() {
	int num;
	long long res = 0; // ÃÑ ÆÁÀÇ ÇÕ
	cin >> num;
	vector<long long> tip(num);
	for (int i = 0; i < num; i++) 
		cin >> tip[i];

	sort(tip.begin(), tip.end(), greater<long long>());
	int tip_temp = 0;
	for (int i = 0; i < num; i++) {
		tip_temp = tip[i] - (i + 1 - 1);
		if (tip_temp < 0) continue;
		res += tip_temp;
	}
	cout << res << endl;
	//for (int i = 0; i < tip.size(); i++) 
		//cout << tip[i] << " ";
	return 0;
}

