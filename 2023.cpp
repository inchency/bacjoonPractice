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
		bool flag = true; // �Ҽ������ƴ���
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
		bool flag = true; // �Ҽ������ƴ���
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
	// ������� �� �ڸ��� �´� �Ҽ� ���� ���� �ű��� �Ҽ��� ã�ƾ���
	ind = 0;
	bool flag = true;
	int ind2 = 0;
	int num;
	int *result = new int[cnt];
	for (int i = 0; i < cnt; i++)
		result[i] = 0;
	for (int z = 0; z < cnt; z++, ind++) {
		flag = true; // �Ҽ������ƴ���
		for (int i = 0; i < nn - 1; i++) {
			if (!flag) break;
			num = arr[ind] / pow(10, i + 1);
			// �Ҽ����� �Ǻ�
			for (int j = 2; j *j <= num; j++) {
				if (num % j == 0) {
					flag = false;
					break;
				}
				
			}
			if (i == nn - 2 && flag == true && num != 1) { // ������ ���ڸ� ���� �ߴµ� �Ҽ��̸� �̰Ŵ� �ű��� �Ҽ���
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