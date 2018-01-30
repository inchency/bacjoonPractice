#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int sum = 0;
	int a, b, c, d; // 천,백,십,일 자리 수
	for (int num = 1; num <= n; num++) {
		if (num / 1000 >= 1) { // 네자리일 때 1000밖에 없음 이것은 한수가 아님
			a = num / 1000;
			b = num % 1000 / 100;
			c = num % 1000 % 100 / 10;
			d = num % 1000 % 100 % 10 / 1;
		}
		else if (num / 100 >= 1) { // 세자리 일 때
			a = 0;
			b = num / 100;
			c = num % 100 / 10;
			d = num % 100 % 10 / 1;
			if (b - c == c - d) {
				//cout << num << endl;
				sum++;
			}
		}
		else { // 두자리 일 때랑 한자리 일 때 무조건 한수
			sum ++; // 1~99
		}
	}
	cout << sum << endl;

	return 0;
}

