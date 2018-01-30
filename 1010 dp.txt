#include <iostream>

using namespace std;

int main() {
	int T, N, M;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N >> M;
		int cnt = 0;
		int **arr = new int*[N];
		for (int j = 0; j < N; j++) {
			arr[j] = new int[M];
		}
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				arr[j][k] = 0;
			}
		}
		for (int j = 0; j < M; j++) {
			arr[0][j] = j+1;
		}
		for (int j = 0; j < N; j++) {
			arr[j][j] = 1;
		}
		for (int j = 1; j < N; j++) {
			for (int k = j + 1; k < M; k++) {
				for (int l = k-1; l >= j-1; l--) {
					arr[j][k] += arr[j - 1][l];
				}
			}
		}
		/*for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cout << arr[j][k] << " ";
			}
			cout << endl;
		}*/

		cout << arr[N-1][M-1] << endl;
		for (int j = 0; j < N; j++) {
			delete[] arr[j];
		}
		delete[] arr;
	}
	return 0;
}