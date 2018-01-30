#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int nn;
	cin >> nn;
	int n = pow(10, nn);
	int ind = 0;
	int cnt = 0;
	
	for (int i = 2; i <= n; i++) {
		bool flag = true; // 소수인지아닌지
		for (int j = 2; j*j <= i; j++) {
			if (i%j == 0) {
				flag = false;
				break;
			}
		}
		if (flag == true) {
			cnt++;
		}
	}
	int *arr = new int[cnt];
	cnt = 0;
	for (int i = 2; i < n; i++) {
		bool flag = true; // 소수인지아닌지
		for (int j = 2; j < i; j++) {
			if (i%j == 0) {
				flag = false;
				break;
			}
		}
		if (flag == true && i/pow(10,(nn-1))>=1) {
			arr[ind++] = i;
			cnt++;
		}
	}
	// 여기까지 각 자리에 맞는 소수 구함 이제 신기한 소수를 찾아야함
	ind = 0;
	bool flag = true;
	int ind2 = 0;
	int num;
	int *result = new int[cnt];
	for (int i = 0; i < cnt; i++)
		result[i] = 0;
	for (int z = 0; z < cnt; z++, ind++) {
		flag = true; // 소수인지아닌지
		for (int i = 0; i < nn - 1; i++) {
			if (!flag) break;
			num = arr[ind] / pow(10, i + 1);
			// 소수인지 판별
			for (int j = 2; j *j <= num; j++) {
				if (num % j == 0) {
					flag = false;
					break;
				}
				
			}
			if (i == nn - 2 && flag == true && num != 1) { // 마지막 끝자리 까지 했는데 소수이면 이거는 신기한 소수임
				result[ind2++] = arr[ind];
			}
		}
	}
	ind = 0;
	while (result[ind] != 0) {
		cout << result[ind++] << endl;
	}
	return 0;
}