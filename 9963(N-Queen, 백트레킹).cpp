#include <iostream>
#include <vector>
#include <cmath>
#define MARK 1
#define UNMARK 0

using namespace std;

class N_Queens {
public:
	int n; // N*N
	int *col; // i�࿡ �� ���� ��ǥ
	N_Queens(int n) {
		this->n = n;
		col = new int[n];
	}

};

void back_tracking(N_Queens nq, int level, int n); // level�� ���� ���� ���� ��ġ
bool isPossible(N_Queens nq, int level); // �� ���°� �������� �Ǻ�

int cnt = 0;

int main() {
	int num;
	cin >> num;
	vector<int>queen(num);
	N_Queens nq(num);
	back_tracking(nq, 0, num);
	cout << cnt;
	return 0;
}

void back_tracking(N_Queens nq, int level, int n) {
	if (level == n) { // n-1���� ���� �ִµ� n���� �Դٴ°��� n-1 ���� ��� ������ ��
		cnt++;
		//for (int i = 0; i < n; i++) cout << nq.col[i] << " ";
		//cout << endl;
		return;
	}
	else { // ���� level-1������ ��� ���Ǵ�� ������ level���� ���� ���� ��Ȳ��
		for (int i = 0; i < n; i++) { // ���� 0������ n-1������ ���� ��츦 ��� ��������.
			nq.col[level] = i;
			if (isPossible(nq, level)) { // ���� i�� ���� �����ϳ�?
				back_tracking(nq, level + 1, n); // �����ϸ� ������ ����
			}
		}
	}
}

bool isPossible(N_Queens nq, int level) {
	for (int i = 0; i < level; i++) { // level ��ġ�� ���� �Ǻ��� ���� ������ �ִ� ���� �� ���� 0~level-1�� ������ �ִ� ���̶� ������ ������ ����.
		if (nq.col[i] == nq.col[level] || abs(level - i) == abs(nq.col[level] - nq.col[i])) { // ���ڷ� �ְų� �밢���϶�(�غ��� ���̰� ������ �밢��)
			return false;
		}
	}
	// for�� �ٵ��Ҵµ� ���� ������
	return true;
}
