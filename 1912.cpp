#include <iostream>
#include <algorithm>
using namespace std;
void dp(int n, long long *arr, int *sum);
int main() {
	int cases;
	cin >> cases;
	long long *arr = new long long[cases];
	int *sum = new int[cases];
	for (int testCases = 0; testCases < cases; testCases++) {
		cin >> arr[testCases];
	}
	dp(cases, arr, sum);
	int max = arr[0];
	for (int i = 1; i < cases; i++) {
		if (max <= sum[i])
			max = sum[i];
	}
	cout << max;
	delete[]arr;
	delete[]sum;
	return 0;
}

void dp(int n, long long *arr, int *sum) {
	for (int i = 0; i < n; i++) {
		if (i == 0)
			sum[0] = arr[0];
		else {
			if (sum[i - 1] + arr[i] >= arr[i])
				sum[i] = sum[i - 1] + arr[i];
			else
				sum[i] = arr[i];
		}
	}
}