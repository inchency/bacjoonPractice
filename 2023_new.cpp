#include <iostream>
using namespace std;

bool isPrime(int n);
void dfs(int a, int b); // a는 첫번째 자리수, b는 진행하고 있는 자리수 1의 자리면 1 2의 자리면 2

int n;

int main() {
	cin >> n;
	for (int i = 2; i <= 7; i++) {
		if (i == 2 || i == 3 || i == 5 || i == 7) {
			dfs(i,1); // 1의 자리 수부터 비교
		}
	}

	return 0;
}

bool isPrime(int n){
	if (n == 1) // 1은 소수 x
		return false;
	else if (n == 2) // 2는 소수
		return true;
	else {
		for (int i = 3; i*i <= n; i++) {
			if (n%i == 0)
				return false;
		}
		return true;
	}
}

void dfs(int a, int b) {
	if (b == n) // 물어본 자리수와 일치하면
		cout << a << endl;
	int temp;
	// 홀수만 비교!
	for (int i = 1; i <= 9; i+=2) {
		temp = a * 10 + i;
		if (isPrime(temp))
			dfs(temp, b + 1);
	}
}