#include <iostream>
#include <vector>

using namespace std;

int dp(vector<vector<int>>arr, vector<vector<int>>&dpTable);

int main() {
	int cases;
	cin >> cases;
	vector<vector<int>>arr;
	vector<vector<int>>dpTable;
	for (int i = 0; i < cases; i++) {
		vector<int>content(i+1);
		arr.push_back(content);
		dpTable.push_back(content);
	}
	for (int i = 0; i < cases; i++) {
		for (int j = 0; j < arr[i].size(); j++) {
			cin >> arr[i][j];
		}
	}
	
		cout << dp(arr, dpTable);
		for (int i = 0; i < cases; i++) {
			for (int j = 0; j < arr[i].size(); j++) {
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}
		for (int i = 0; i < cases; i++) {
			for (int j = 0; j < arr[i].size(); j++) {
				cout << dpTable[i][j] << " ";
			}
			cout << endl;
		}
	return 0;
}

int dp(vector<vector<int>>arr, vector<vector<int>>&dpTable) {
	if (arr.size() == 1) return arr[0][0]; // cases가 1일 때
	dpTable[0][0] = arr[0][0]; //dpTable의 초기값 설정
	dpTable[1][0] = dpTable[0][0] + arr[1][0];
	dpTable[1][1] = dpTable[0][0] + arr[1][1]; // 여기까지는 고정되있는 초기값
	for (int i = 2; i < arr.size(); i++) {
		for (int j = 0; j < arr[i].size(); j++) {
			if (j == 0) { // 맨 왼쪽놈 때
				dpTable[i][j] = dpTable[i - 1][j] + arr[i][j];
			}
			else if (j == arr[i].size() - 1){ // 맨 오른쪽 놈일때
				dpTable[i][j] = dpTable[i - 1][j - 1] + arr[i][j];
			}
			else { // 맨왼쪽과 오른쪽이 아닐 때
				if (dpTable[i - 1][j - 1] > dpTable[i - 1][j]) dpTable[i][j] = dpTable[i - 1][j - 1] + arr[i][j];
				else dpTable[i][j] = dpTable[i - 1][j] + arr[i][j];
			}
		}
	}
	// 최대값 찾기
	int maxNum = dpTable[dpTable.size() - 1][0];
	for (int j = 0; j < dpTable[dpTable.size() - 1].size(); j++) 
		if (maxNum <= dpTable[dpTable.size() - 1][j]) maxNum = dpTable[dpTable.size() - 1][j];
	return maxNum;
}