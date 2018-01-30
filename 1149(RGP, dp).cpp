#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp(vector<vector<int>>inputTable, vector<vector<int>>dpTable);

int main() {
	vector<vector<int>>inputTable;
	vector<vector<int>>dpTable;
	int num;
	cin >> num;
	for (int i = 0; i < 3; i++) {
		vector<int>element(num);
		inputTable.push_back(element);
		dpTable.push_back(element);
	}
	for (int j = 0; j < num; j++) {
		cin >> inputTable[0][j];
		cin >> inputTable[1][j];
		cin >> inputTable[2][j];
	}
	// dpTable 기본값 초기화
	dpTable[0][0] = inputTable[0][0]; dpTable[1][0] = inputTable[1][0]; dpTable[2][0] = inputTable[2][0];
	cout << dp(inputTable, dpTable);
	return 0;
}

int dp(vector<vector<int>>inputTable, vector<vector<int>>dpTable){ // dpTable에 최소값을 채워나가야함 inputTable을 이용해서
	for (int j = 1; j < inputTable[0].size(); j++) {
		dpTable[0][j] = dpTable[1][j - 1] < dpTable[2][j - 1] ? dpTable[1][j - 1] + inputTable[0][j] : dpTable[2][j - 1] + inputTable[0][j];
		dpTable[1][j] = dpTable[0][j - 1] < dpTable[2][j - 1] ? dpTable[0][j - 1] + inputTable[1][j] : dpTable[2][j - 1] + inputTable[1][j];
		dpTable[2][j] = dpTable[0][j - 1] < dpTable[1][j - 1] ? dpTable[0][j - 1] + inputTable[2][j] : dpTable[1][j - 1] + inputTable[2][j];
	}
	int min = dpTable[0].back();
	for (int i = 1; i < 3; i++) 
		if (min > dpTable[i].back()) 
			min = dpTable[i].back();
	return min;
}
