#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	long long treeNum, length;
	cin >> treeNum >> length;
	vector<long long>arr;
	for (int i = 0; i < treeNum; i++) {
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}
	long long sum = 0;
	long long max = 0;
	for (int i = 0; i < treeNum; i++) {
		if (max < arr[i]) max = arr[i];
	}
	int first = 1, last = max;
	int middle;
	while (first <= last) {
		sum = 0;
		middle = (first + last) / 2;
		for (int i = 0; i < treeNum; i++) {
			sum += arr[i] - middle > 0 ? arr[i] - middle : 0;
		}
		if (sum < length) 
			last = middle - 1;
		else 
			first = middle + 1;
	}
	cout << last;
}