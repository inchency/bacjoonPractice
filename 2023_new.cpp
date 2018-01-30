#include <iostream>
using namespace std;

bool isPrime(int n);
void dfs(int a, int b); // a�� ù��° �ڸ���, b�� �����ϰ� �ִ� �ڸ��� 1�� �ڸ��� 1 2�� �ڸ��� 2

int n;

int main() {
	cin >> n;
	for (int i = 2; i <= 7; i++) {
		if (i == 2 || i == 3 || i == 5 || i == 7) {
			dfs(i,1); // 1�� �ڸ� ������ ��
		}
	}

	return 0;
}

bool isPrime(int n){
	if (n == 1) // 1�� �Ҽ� x
		return false;
	else if (n == 2) // 2�� �Ҽ�
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
	if (b == n) // ��� �ڸ����� ��ġ�ϸ�
		cout << a << endl;
	int temp;
	// Ȧ���� ��!
	for (int i = 1; i <= 9; i+=2) {
		temp = a * 10 + i;
		if (isPrime(temp))
			dfs(temp, b + 1);
	}
}