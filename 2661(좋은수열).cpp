#include <iostream>
#include <vector>
using namespace std;

bool isRight(int num, vector<int>arr);
void backTracking(int num, vector<int>arr);

int main() {
	int num;
	cin >> num;
	vector<int>arr(num);
	arr[0] = 1; // ó���� ������ 1 ��
	backTracking(0, arr);
	return 0;
}

void backTracking(int num, vector<int>arr) {
	bool flag = false;
	static bool answer_flag = false; //�ѹ� �ּҰ��� ���ϸ� ���� ���� ������ �����ʿ䰡 ����
	if (answer_flag) return; // ���̻� �� �ʿ� ���� ������ return
	if (isRight(num, arr)) {
		flag = true;
		if (num == arr.size() - 1) { // ������ ����������
			for (int i = 0; i < arr.size(); i++)  // ����ϱ�
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
			if (arr[j] != arr[j - num_len]) // �ٸ��� break ���̻� ���� �ʿ� x
				break;
			if (j == num - num_len + 1) // ���� ��� ��ġ�ؼ� ���������� ��ġ�ϸ�
				return false;
		}
		num_len++;
	}
	return true;
}