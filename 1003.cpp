#include <iostream>

using namespace std;

void fibo(int n, int ** ary);

int main() {
	int cases, num;
	cin >> cases;
	for (int testCases = 0; testCases < cases; testCases++) {
		cin >> num;
		int **ary = new int*[num+1];
		for (int i = 0; i < num + 1; i++) {
			ary[i] = new int[2];
		}
		fibo(num + 1, ary);
		for (int i = 0; i < num + 1; i++) {
			delete[] ary[i];
		}
		delete[] ary;
	}
	return 0;
}

void fibo(int n, int ** ary) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			if (i == 0) {
				ary[0][0] = 1; 
				ary[0][1] = 0;
			}
			else if (i == 1) {
				ary[1][0] = 0; ary[1][1] = 1; // 초기값 저장
			}
			else {
				ary[i][j] = ary[i - 2][j] + ary[i - 1][j];
			}
		}
	}
	cout << ary[n-1][0] << " " << ary[n-1][1] << endl;
}