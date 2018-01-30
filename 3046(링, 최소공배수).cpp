#include <iostream>
#include <vector>
using namespace std;

int func();

int main() {
	//int num;
	//cin >> num;
	//vector<int>arr(num);
	//for (int i = 0; i < num; i++) 
	//	cin >> arr[i];
	//for (int i = 1; i < num; i++) {
	//	// 최대공약수 구하기
	//	cout << 12 / gcd(12, arr[i]) << "/" << arr[i] / gcd(12, arr[i]);
	//	cout << endl;
	//}
	cout << func();
	

	return 0;
}

int func() {
	int cnt = 0;
	for (int i = 0; i <= 1024; ++i) {
		if ((i & (i - 1)) == 0) {
			++cnt;
		}
	}
	return cnt;
}