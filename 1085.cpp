#include <iostream>
#include <algorithm>
using namespace std;
int shortest(int a, int b, int c, int d);
bool des(int a, int b);

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	cout << shortest(a, b, c, d);
	return 0;
}
int shortest(int a, int b, int c, int d) {
	int res=0;
	int ary[4];
	int f, s, t, fo;
	f = a - 0;
	s = b - 0;
	t = c - a;
	fo = d - b;
	ary[0] = f; ary[1] = s; ary[2] = t; ary[3] = fo;
	sort(ary, ary + 4, des);
	res = ary[0];
	return res;
}
bool des(int a, int b) {
	return a < b;
}