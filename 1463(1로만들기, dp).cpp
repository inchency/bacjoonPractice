#include <iostream>
#include <vector>

using namespace std;

int dp(vector<int>dpTable, int num);

int main() {
	int num;
	cin >> num;
	vector<int>dpTable(num + 1);
	cout << dp(dpTable, num);

	return 0;
}
int dp(vector<int>dpTable, int num) {
	dpTable[0] = 0; dpTable[1] = 0; dpTable[2] = 1; dpTable[3] = 1;// 0,1,2,3 �� �� 0,0,1,1 ����
	for (int i = 4; i <= num; i++) {
		int temp2, temp3, temp4; // 2�� 3���� �������� ���� -1�� ���
		int min;
		if ((i % 2 == 0) && (i % 3 == 0)) { // �Ѵ� ��������
			temp2 = i / 2;
			temp3 = i / 3;
			temp4 = i - 1;
			min = dpTable[temp2];  // �ּҰ� ã������
			if (min > dpTable[temp3]) {
				if (dpTable[temp3] > dpTable[temp4]) {
					min = dpTable[temp4];
				}
				else min = dpTable[temp3];
			}
			else {
				if (min > dpTable[temp4]) {
					min = dpTable[temp4];
				}
			}
		}
		else if (i % 2 == 0) { // 2�� ��������
			temp2 = i / 2;
			temp4 = i - 1;
			min = dpTable[temp2]; // �ּҰ� ã�� ����
			if (min > dpTable[temp4]) {
				min = dpTable[temp4];
			}
		}
		else if (i % 3 == 0) { // 3���� ��������
			temp3 = i / 3;
			temp4 = i - 1;
			min = dpTable[temp3]; // �ּҰ� ã�� ����
			if (min > dpTable[temp4]) {
				min = dpTable[temp4];
			}
		}
		else if ((i % 2 != 0) && (i % 3 != 0)) { // 2�� 3���� �ȴ����� -1
			min = dpTable[i - 1];
		}
		dpTable[i] = 1 + min;
	}
	//for(int i=1; i<=num; i++)cout << dpTable[i] << " ";
	return dpTable[num];
}