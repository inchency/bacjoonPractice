#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int sum = 0;
	int a, b, c, d; // õ,��,��,�� �ڸ� ��
	for (int num = 1; num <= n; num++) {
		if (num / 1000 >= 1) { // ���ڸ��� �� 1000�ۿ� ���� �̰��� �Ѽ��� �ƴ�
			a = num / 1000;
			b = num % 1000 / 100;
			c = num % 1000 % 100 / 10;
			d = num % 1000 % 100 % 10 / 1;
		}
		else if (num / 100 >= 1) { // ���ڸ� �� ��
			a = 0;
			b = num / 100;
			c = num % 100 / 10;
			d = num % 100 % 10 / 1;
			if (b - c == c - d) {
				//cout << num << endl;
				sum++;
			}
		}
		else { // ���ڸ� �� ���� ���ڸ� �� �� ������ �Ѽ�
			sum ++; // 1~99
		}
	}
	cout << sum << endl;

	return 0;
}

