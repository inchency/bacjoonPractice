#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

/*
* Description :
* Time complexity:
* Space complexity:
*/
int isEnableDrive(const vector<int> &E, const vector<int> &C) {
	// E�� ������ �ִ� ������, C�� �Ҹ�Ǵ� �⸧��
	int s = E.size(); // ������ ����
	int ESum, CSum, cnt, index; // ������ ��
	for (int z = 0; z < s; z++) { // z=0 0������ index���� Ž���� �Ұ���
		ESum = 0, CSum = 0; // ������ �� �ʱ�ȭ
		cnt = 0; // �ε��� �Ѿ�� ��쵵 ����
		index = z; // z�� �ʱ�ȭ
		bool flag = false; // ������ ��ġ�� falg = true �� ����
		while (cnt <= s) { // cnt�� �������� ���� �� ����
			if (index == s) { // z�� �ε����� �������� �Ѿ� �������� �Դٸ�
				index = 0; // index�� 0���� �ʱ�ȭ (�ٽ� ó������ ��ȯ�̹Ƿ�)
			}
			ESum += E[index];
			CSum += C[index];
			if (ESum < CSum) 
				break; // �ȵǴ� ���̽��Ƿ� while ������ �������� ���� index�� �Ѿ��.
			if (cnt == s)
				flag = true; // ���������� �Ǻ��ߴµ� �����ϸ� �װ��� ������ index (�ּҺ��� ������)
			index++;
			cnt++;
		}
		if (flag) return z; // z�� �ε����� ��ȯ
	}
	return -1; // ���� ������ ����� ���� ������ -1�� ��ȯ
}

int main(int argc, const char *argv[]) {
	int T = 0, N = 0;

	cin >> T;
	for (int i = 0; i < T; i++) {
		vector<int> E, C;
		cin >> N;

		for (int i = 0; i < N; i++) {
			int energy = 0;
			cin >> energy;
			E.push_back(energy);
		}

		for (int i = 0; i < N; i++) {
			int cost = 0;
			cin >> cost;
			C.push_back(cost);
		}

		cout << isEnableDrive(E, C) << endl;
	}
}
