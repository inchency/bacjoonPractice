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
		// 2���� ���� �����
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
	int n = dpt[0].size(); // n�� ������ �ִ� n ����
	// dp ���̺� [0][0]�� [1][0]�� 0,0 �ֱ�
	dpt[0].push_front(0);
	dpt[1].push_front(0);
	// dpt2 �����ϱ� (dpt2�� ���� dp ������ ���� ���̺�)
	vector<deque<int>>dpt2;
	dpt2 = dpt;
	int res;
	if (n == 1) 
		res = dpt[0][1] > dpt[1][1] ? dpt[0][1] : dpt[1][1]; // n 1�϶��� ū�� �� �̱�
	else {
		for (int j = 2; j < dpt2[0].size(); j++) {
			dpt2[0][j] = dpt2[1][j - 1] > dpt2[1][j - 2] ? dpt2[1][j - 1] + dpt[0][j] : dpt2[1][j - 2] + dpt[0][j]; // ���� dpt�� �̿�
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