#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int haveNum;
	cin >> haveNum;
	vector<int>haveNumArr;
	for (int i = 0; i < haveNum; i++) {
		int temp;
		cin >> temp;
		haveNumArr.push_back(temp);
	}
	int checkNum;
	cin >> checkNum;
	vector<int>checkNumArr;
	for (int i = 0; i < checkNum; i++) {
		int temp;
		cin >> temp;
		checkNumArr.push_back(temp);
	}
	sort(haveNumArr.begin(), haveNumArr.end());
	sort(checkNumArr.begin(), checkNumArr.end());
	for (int i = 0; i<haveNumArr.size(); i++) {
		cout << haveNumArr[i] << " ";
	}
	cout << endl;
	for (int i = 0; i<checkNumArr.size(); i++) {
		cout << checkNumArr[i] << " ";
	}
	for (int i = 0; i < checkNumArr.size(); i++) {
		
	}
	return 0;
}