#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std;

bool IsPrime(int num); // 소수 판별 함수

int main() {
	int numCases;
	scanf("%d", &numCases);
	for (int i = 0; i < numCases; i++) {
		int num;
		scanf("%d", &num);
		vector<int>arr;
		set<int>setArr;
		int numLen;
		if (num / 1000000 >= 1) {
			arr.push_back(num / 1000000);
			arr.push_back(num / 100000 % 10);
			arr.push_back(num / 10000 % 10);
			arr.push_back(num / 1000 % 10);
			arr.push_back(num / 100 % 10);
			arr.push_back(num / 10 % 10);
			arr.push_back(num);
			numLen = 7; // 문제에서 최대 7자리 수
		}
		else if (num / 100000 >= 1) {
			arr.push_back(num / 100000 % 10);
			arr.push_back(num / 10000 % 10);
			arr.push_back(num / 1000 % 10);
			arr.push_back(num / 100 % 10);
			arr.push_back(num / 10 % 10);
			arr.push_back(num);
			numLen = 6;
		}
		else if (num / 10000 >= 1) {
			arr.push_back(num / 10000);
			arr.push_back(num / 1000 % 10);
			arr.push_back(num / 100 % 10);
			arr.push_back(num / 10 % 10);
			arr.push_back(num % 10);
			numLen = 5;
		}
		else if (num / 1000 >= 1) {
			arr.push_back(num / 1000);
			arr.push_back(num / 100 % 10);
			arr.push_back(num / 10 % 10);
			arr.push_back(num);
			numLen = 4;
		}
		else if (num / 100 >= 1) {
			arr.push_back(num / 100);
			arr.push_back(num / 10 % 10);
			arr.push_back(num % 10);
			numLen = 3;
		}
		else if (num / 10 >= 1) {
			arr.push_back(num / 10);
			arr.push_back(num % 10);
			numLen = 2;
		}
		else {
			arr.push_back(num);
			numLen = 1;
		}
		//cout << IsPrime(num) << endl;
		for (int j = 0; j < arr.size(); j++) {
			next_permutation(arr.begin(), arr.end());
			cout << arr[0] << " " << arr[1] << " " << arr[2] << endl;
		}
	}

	return 0;
}

// 에라토스테네스 이용
bool IsPrime(int num) {
	bool result = true;
	for (int i = 2; i <= sqrt(num); ++i) {
		if (num % i == 0) {
			result = false;
			break;
		}
	}
	return result;
	/*if (num <= 1) return false;
	int half = num / 2;
	for (int i = 2; i <= half; i++)
		if (num%i == 0) return false;
	return true;*/
}