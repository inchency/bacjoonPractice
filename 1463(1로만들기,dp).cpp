#include <iostream>
#include <vector>

using namespace std;

int dp(vector<int>dpTable, int num);

int main() {
	int num;
	cin >> num;
	vector<int>dpTable(num);
	cout << dp(dpTable, num);

	return 0;
}
int dp(vector<int>dpTable, int num){
	dpTable[0] = 0; dpTable[1] = 0; dpTable[2] = 1; dpTable[3] = 1;// 0,1,2,3 일 때 0,0,1,1 삽입
	for (int i = 4; i <= num; i++) {
		int temp2, temp3, temp4; // 2와 3으로 나눠지는 경우와 -1의 경우
		if (i % 2 == 0) { // 2로 나눠지면
			temp2 = i / 2;
		}
		if (i % 3 == 0) { // 3으로 나눠지면
			temp3 = i / 3;
		}
		if ((i % 2 != 0) && (i % 3 != 0)) { // 2와 3으로 안눠지면 -1
			temp4 = i - 1;
		}
		int min = dpTable[temp2];  // 최소값 찾기위해
		if (min > dpTable[temp3]) {
			if (dpTable[temp3] > dpTable[temp4]) {
				min = dpTable[4];
			}
			else min = dpTable[3];
		}
		else {
			if (min > dpTable[temp4]) {
				min = dpTable[temp4];
			}
		}
		dpTable[i] = 1 + dpTable[min];
	}
	for (int i = 1; i <= num; i++) {
		cout << dpTable[i] << " ";
	}
	return dpTable[num];
}