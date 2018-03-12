#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long binarySearch(long long right, long long left, vector<long long>&arr, long long K, long long N);

int main() {
	long long K, N;
	scanf("%lld %lld", &K, &N);
	vector<long long>arr;
	for (int i = 0; i < K; i++) {
		long long lengthTemp;
		scanf("%lld", &lengthTemp);
		arr.push_back(lengthTemp);
	}
	int right = *max_element(arr.begin(), arr.end());
	printf("%lld", binarySearch(right, 1, arr, K, N));
	return 0;
}

long long binarySearch(long long right, long long left, vector<long long>&arr, long long K, long long N){
	long long cnt = 0;
	long long middle = (right+left)/2;
	while (right >= left) {
		for (int i = 0; i < K; i++) 
			cnt += arr[i] / middle;
		if (cnt < N) { // 랜선의 갯수가 적어서 크기를 줄여서 랜선의 갯수를 늘려야함
			right = middle-1;
			middle = (right + left) / 2;
			cnt = 0;
		}
		else if(cnt >= N){
			left = middle+1;
			middle = (right + left) / 2;
			cnt = 0;
		}
	}
	return middle;
}