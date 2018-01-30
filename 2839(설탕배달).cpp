#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void dynamicProgramming(vector<int>&arr);
void printDpTable(vector<int>arr); // 테스트용 출력함수
void answerDpTable(vector<int>arr); // 답 내는 함수
int main() {
	int num;
	cin >> num;
	vector<int>dpTable(num+1);
	// 초기값 채우기
	dpTable[0] = -1; dpTable[1] = -1; dpTable[2] = -1; dpTable[3] = 1; dpTable[4] = -1; dpTable[5] = 1; // -1은 못채우는 경우
	dynamicProgramming(dpTable);
	// printDpTable(dpTable);
	answerDpTable(dpTable);
	return 0;
}
void dynamicProgramming(vector<int>&arr) {
	// dpTable을 채워나간다.
	for (int i = 6; i < arr.size(); i++) {
		// 우선 -1일 때 걸러야한다.
		if (arr[i - 3] == -1 && arr[i - 5] == -1) // 둘다 불가능 할 때
			arr[i] = -1;
		else if (arr[i - 3] == -1 && arr[i - 5] != -1) // 3에서 온거만 -1일 때
			arr[i] = arr[i - 5] + 1;
		else if (arr[i - 3] != -1 && arr[i - 5] == -1) // 5에서 온거만 -1일 때
			arr[i] = arr[i - 3] + 1;
		else
			arr[i] = min(arr[i - 3], arr[i - 5]) + 1;
	}
}
void printDpTable(vector<int>arr) {
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
}

void answerDpTable(vector<int>arr) {
	cout << arr[arr.size() - 1];
}