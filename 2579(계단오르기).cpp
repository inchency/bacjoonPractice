#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp(vector<int>arr);
int main() {
	int num;
	cin >> num;
	vector<int>arr(num);
	for (int i = 0; i < num; i++)
		cin >> arr[i];
	cout << dp(arr);
	return 0;
}
int dp(vector<int>arr){
	vector<int>dpTable(arr.size());
	if (arr.size() == 1) return arr[0];
	else if (arr.size() == 2) return arr[0] + arr[1];
	else if (arr.size() == 3) return arr[0] + arr[2] > arr[1] + arr[2] ? arr[0] + arr[2] : arr[1] + arr[2];
	else {
		dpTable[0] = arr[0]; dpTable[1] = arr[0] + arr[1]; dpTable[2] = arr[0] + arr[2] > arr[1] + arr[2] ? arr[0] + arr[2] : arr[1] + arr[2]; // 초기 dpTable 설정
		for (int i = 3; i < arr.size(); i++) {
			dpTable[i] = max(dpTable[i - 3] + arr[i - 1] + arr[i], dpTable[i - 2] + arr[i]);
		}
		return dpTable[dpTable.size() - 1];
	}
}