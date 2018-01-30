#include <iostream>
#include <vector>
using namespace std;

bool isRight(int num, vector<int>arr);
void backTracking(int num, vector<int>arr);

int main() {
	int num;
	cin >> num;
	vector<int>arr(num);
	arr[0] = 1; // 처음은 무조건 1 들어감
	backTracking(0, arr);
	return 0;
}

void backTracking(int num, vector<int>arr) {
	bool flag = false;
	static bool answer_flag = false; //한번 최소값을 구하면 다음 착한 수열은 구할필요가 없음
	if (answer_flag) return; // 더이상 할 필요 없기 때문에 return
	if (isRight(num, arr)) {
		flag = true;
		if (num == arr.size() - 1) { // 끝까지 도달했으면
			for (int i = 0; i < arr.size(); i++)  // 출력하기
				cout << arr[i];
			answer_flag = true;
			return;
		}
		arr[num + 1] = 1;
		backTracking(num + 1, arr);
		if (!flag) num--;
		arr[num + 1] = 2;
		backTracking(num + 1, arr);
		if (!flag) num--;
		arr[num + 1] = 3;
		backTracking(num + 1, arr);
		return;
	}
	else {
		return;
	}
}

bool isRight(int num, vector<int>arr) {
	int num_len = 1;
	while (num_len <= (num+1) / 2) {
		for (int j = num; j > num - num_len; j--) {
			if (arr[j] != arr[j - num_len]) // 다르면 break 더이상 비교할 필요 x
				break;
			if (j == num - num_len + 1) // 만약 계속 일치해서 마지막까지 일치하면
				return false;
		}
		num_len++;
	}
	return true;
}