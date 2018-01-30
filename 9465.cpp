#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int dp(vector<deque<int>> dpt);

int main() {
	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		int n;
		cin >> n;
		vector<deque<int>>dpTable;
		// 2차원 백터 만들기
		for (int j = 0; j < 2; j++) {
			deque<int>element(n);
			dpTable.push_back(element);
		}
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < n; k++) {
				cin >> dpTable[j][k];
			}
		}
		cout << dp(dpTable) << endl;
		/*for (int j = 0; j < 2; j++) {
			for (int k = 0; k < n; k++) {
				cout << dpTable[j][k] << " ";
			}
			cout << endl;
		}*/

	}
	return 0;
}

int dp(vector<deque<int>>dpt) {
	int n = dpt[0].size(); // n에 기존에 있던 n 저장
	// dp 테이블에 [0][0]과 [1][0]에 0,0 넣기
	dpt[0].push_front(0);
	dpt[1].push_front(0);
	// dpt2 복제하기 (dpt2가 실제 dp 데이터 쌓일 테이블)
	vector<deque<int>>dpt2;
	dpt2 = dpt;
	int res;
	if (n == 1) 
		res = dpt[0][1] > dpt[1][1] ? dpt[0][1] : dpt[1][1]; // n 1일때는 큰거 걍 뽑기
	else {
		for (int j = 2; j < dpt2[0].size(); j++) {
			dpt2[0][j] = dpt2[1][j - 1] > dpt2[1][j - 2] ? dpt2[1][j - 1] + dpt[0][j] : dpt2[1][j - 2] + dpt[0][j]; // 원래 dpt도 이용
			dpt2[1][j] = dpt2[0][j - 1] > dpt2[0][j - 2] ? dpt2[0][j - 1] + dpt[1][j] : dpt2[0][j - 2] + dpt[1][j];
		}
		res = dpt2[0][n] > dpt2[1][n] ? dpt2[0][n] : dpt2[1][n];
		/*for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 6; k++) {
				cout << dpt2[j][k] << " ";
			}
			cout << endl;
		}*/
	}
	return res;
}