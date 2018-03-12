#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void nQueen(vector<int>&arr, int N, int col);

int cnt = 0;

int main() {
	int N;
	scanf("%d", &N);
	vector<int>arr(N);
	for (int i = 0; i < N; i++) {
		arr[0] = i;
		nQueen(arr, N, 1); // 1행부터 검사 시작
	}
	printf("%d", cnt);
	return 0;
}

void nQueen(vector<int>&arr, int N, int col) {
	if (col == N) {
		cnt++;
		return;
	}
	for (int row = 0; row < N; row++) {
		bool flag = true;
		for (int i = 0; i < col; i++) {
			if ((row == arr[i]) || abs(col - i) == abs(row - arr[i])) {
				flag = false;
				break;
			}
		}
		if (flag) {
			arr[col] = row;
			nQueen(arr, N, col + 1);
		}
	}
}