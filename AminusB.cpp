#include <iostream>

using namespace std;

int main() {
	int n, a, b;
	cin >> n >> a >> b;
	int cnt = 0;
	while (1) {
		if (a == b) break;
		a = (a + 1) / 2;
		b = (b + 1) / 2;
		cnt++;
	}
	cout << cnt;
	return 0;
}

/*
#include <iostream>
#include <algorithm>

using namespace std;

bool asc(int a, int b);

int main() {
	int cnt;
	cin >> cnt;
	int *num = new int[cnt];
	for (int i = 0; i < cnt; i++)
		cin >> num[i];
	sort(num, num + cnt, asc);
	for (int i = 0; i < cnt; i++)
		cout << num[i] << " ";
	return 0;
}

bool asc(int a, int b) {
	return a < b;
}
*/