#include <iostream>
using namespace std;

int d(int n) {
	int num;
	int one, two, three, four;
	if (n < 10) { // 1자리 일 때
		num = n + n;
	}
	else if (n < 100) { // 2자리 일 때
		one = n % 10; // 1의 자리
		two = n / 10; // 2의자리
		num = n + one + two;
	}
	else if (n < 1000) { // 3자리 일 때
		one = n % 10;
		two = n % 100 / 10;
		three = n / 100;
		num = n + one + two + three;
	}
	else if (n < 10000) { // 4자리 일 때
		one = n % 10;
		two = n % 100 / 10;
		three = n % 1000 / 100;
		four = n / 1000;
		num = n + one + two + three + four;
	}
	else if (n == 10000) { // 5자리 일 때
		num = n + 1;
	}
	if (num > 10000)
		return 0;
	return num;
}

int main() {
	bool ary[10001];
	// 모두 true로 초기화 즉 생성자로 가정
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