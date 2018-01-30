#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void dynamicProgramming(vector<int>&arr);
void printDpTable(vector<int>arr); // �׽�Ʈ�� ����Լ�
void answerDpTable(vector<int>arr); // �� ���� �Լ�
int main() {
	int num;
	cin >> num;
	vector<int>dpTable(num+1);
	// �ʱⰪ ä���
	dpTable[0] = -1; dpTable[1] = -1; dpTable[2] = -1; dpTable[3] = 1; dpTable[4] = -1; dpTable[5] = 1; // -1�� ��ä��� ���
	dynamicProgramming(dpTable);
	// printDpTable(dpTable);
	answerDpTable(dpTable);
	return 0;
}
void dynamicProgramming(vector<int>&arr) {
	// dpTable�� ä��������.
	for (int i = 6; i < arr.size(); i++) {
		// �켱 -1�� �� �ɷ����Ѵ�.
		if (arr[i - 3] == -1 && arr[i - 5] == -1) // �Ѵ� �Ұ��� �� ��
			arr[i] = -1;
		else if (arr[i - 3] == -1 && arr[i - 5] != -1) // 3���� �°Ÿ� -1�� ��
			arr[i] = arr[i - 5] + 1;
		else if (arr[i - 3] != -1 && arr[i - 5] == -1) // 5���� �°Ÿ� -1�� ��
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