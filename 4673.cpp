#include <iostream>
using namespace std;

int d(int n) {
	int num;
	int one, two, three, four;
	if (n < 10) { // 1�ڸ� �� ��
		num = n + n;
	}
	else if (n < 100) { // 2�ڸ� �� ��
		one = n % 10; // 1�� �ڸ�
		two = n / 10; // 2���ڸ�
		num = n + one + two;
	}
	else if (n < 1000) { // 3�ڸ� �� ��
		one = n % 10;
		two = n % 100 / 10;
		three = n / 100;
		num = n + one + two + three;
	}
	else if (n < 10000) { // 4�ڸ� �� ��
		one = n % 10;
		two = n % 100 / 10;
		three = n % 1000 / 100;
		four = n / 1000;
		num = n + one + two + three + four;
	}
	else if (n == 10000) { // 5�ڸ� �� ��
		num = n + 1;
	}
	if (num > 10000)
		return 0;
	return num;
}

int main() {
	bool ary[10001];
	// ��� true�� �ʱ�ȭ �� �����ڷ� ����
	for (int i = 0; i < 10000; i++) {
		ary[i] = true;
	}
	for (int i = 0; i <= 10000; i++) {
		ary[d(i)] = false;
	}
	for (int i = 0; i <= 10000; i++) {
		if (ary[i]) cout << i << endl;
	}
	return 0;
}