#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

bool IsPrime(int num); // 소수 판별 함수
int permutation(vector<int> &vecInt, int r); // nCr 하기 위한 함수

int main() {
	int numCases;
	scanf("%d", &numCases);
	for (int i = 0; i < numCases; i++) {
		string tempNum;
		cin >> tempNum;
		if (tempNum[0] == '0') {
			try {
				int temp = tempNum[0];
				tempNum[0] = tempNum[1];
				tempNum[1] = temp;
			}
			catch (exception e) {
				// 한자리 일 때 예외가 생김
			}
		}
		int num = atoi(tempNum.c_str()); // string으로 받았다 int로 바꿔주는 비 효율적인 짓을 한 이유는 처음에 int로 받았다가 011 에서 0을 인식못하는 낭패를 보았기 때문 코드를 고치긴 귀찮아서..
		vector<int>arr;
		int numLen;
		if (num / 1000000 >= 1) {
			arr.push_back(num / 1000000);
			arr.push_back(num / 100000 % 10);
			arr.push_back(num / 10000 % 10);
			arr.push_back(num / 1000 % 10);
			arr.push_back(num / 100 % 10);
			arr.push_back(num / 10 % 10);
			arr.push_back(num % 10);
			numLen = 7; // 문제에서 최대 7자리 수
		}
		else if (num / 100000 >= 1) {
			arr.push_back(num / 100000 % 10);
			arr.push_back(num / 10000 % 10);
			arr.push_back(num / 1000 % 10);
			arr.push_back(num / 100 % 10);
			arr.push_back(num / 10 % 10);
			arr.push_back(num % 10);
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
			arr.push_back(num % 10);
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
		sort(arr.begin(), arr.end());
		set<int>setArr;
		set<int>::iterator iter;
		for (int r = 1; r <= arr.size(); r++) { // r은 nCr의 r
			while (1) {
				if (r == 1) {
					for (int i = 0; i < arr.size(); i++)
						setArr.insert(arr[i]);
				}
				else if (r == 2) 
					setArr.insert(arr[0] * 10 + arr[1]);
				else if (r == 3)
					setArr.insert(arr[0] * 100 + arr[1] * 10 + arr[2]);
				else if (r == 4)
					setArr.insert(arr[0] * 1000 + arr[1] * 100 + arr[2] * 10 + arr[3]);
				else if (r == 5)
					setArr.insert(arr[0] * 10000 + arr[1] * 1000 + arr[2] * 100 + arr[3] * 10 + arr[4]);
				else if (r == 6)
					setArr.insert(arr[0] * 100000 + arr[1] * 10000 + arr[2] * 1000 + arr[3] * 100 + arr[4] * 10 + arr[5]);
				else if (r == 7)
					setArr.insert(arr[0] * 1000000 + arr[1] * 100000 + arr[2] * 10000 + arr[3] * 1000 + arr[4] * 100 + arr[5] * 10 + arr[6]);
				if (!permutation(arr, r))
					break;
			}
		}
		int answer = 0;
		for (iter = setArr.begin(); iter != setArr.end(); iter++) {
			//printf("%d\n", *iter);
			if (IsPrime(*iter)) {
				//printf("%d ", *iter);
				answer++;
			} 
		}
		printf("%d\n", answer);
	}
	return 0;
}

// 에라토스테네스 이용
bool IsPrime(int num) {
	bool result = true;
	if (num <= 1) return false;
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

int permutation(vector<int> &vecInt, int r)
{
	reverse(vecInt.begin() + r, vecInt.end());
	return next_permutation(vecInt.begin(), vecInt.end());
}