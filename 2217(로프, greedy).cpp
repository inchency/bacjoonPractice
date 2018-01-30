#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
	int cases;
	cin >> cases;
	vector<int>arr;
	for (int i = 0; i < cases; i++) {
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}
	sort(arr.begin(), arr.end(), greater<int>()); // 내림차순 정렬
	int max = arr[0];
	for (int i = 1; i < arr.size(); i++) {
		int sum = arr[i] * (i+1);
		if (sum >= max) {
			max = sum;
		}
	}
	cout << max;
	/*vector<int>::iterator it;
	for (it = arr.begin(); it != arr.end(); it++) {
		cout << *it;
	}*/
	return 0;
}
