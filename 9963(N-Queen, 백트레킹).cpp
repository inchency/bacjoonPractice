#include <iostream>
#include <vector>
#include <cmath>
#define MARK 1
#define UNMARK 0

using namespace std;

class N_Queens {
public:
	int n; // N*N
	int *col; // i행에 들어갈 퀸의 좌표
	N_Queens(int n) {
		this->n = n;
		col = new int[n];
	}

};

void back_tracking(N_Queens nq, int level, int n); // level은 현재 따질 행의 위치
bool isPossible(N_Queens nq, int level); // 퀸 놓는게 가능한지 판별

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
	if (level == n) { // n-1까지 행이 있는데 n까지 왔다는것은 n-1 까지 모두 만족한 것
		cnt++;
		//for (int i = 0; i < n; i++) cout << nq.col[i] << " ";
		//cout << endl;
		return;
	}
	else { // 현재 level-1까지는 모두 조건대로 만족함 level열에 퀸을 놓는 상황임
		for (int i = 0; i < n; i++) { // 퀸을 0번부터 n-1번까지 놓는 경우를 모두 따져본다.
			nq.col[level] = i;
			if (isPossible(nq, level)) { // 퀸을 i에 놓는 가능하냐?
				back_tracking(nq, level + 1, n); // 가능하면 다음행 진행
			}
		}
	}
}

bool isPossible(N_Queens nq, int level) {
	for (int i = 0; i < level; i++) { // level 위치에 현재 판별할 퀸이 놓여져 있는 상태 그 퀸과 0~level-1에 놓여져 있는 퀸이랑 문제가 없는지 본다.
		if (nq.col[i] == nq.col[level] || abs(level - i) == abs(nq.col[level] - nq.col[i])) { // 일자로 있거나 대각선일때(밑변과 높이가 같으면 대각선)
			return false;
		}
	}
	// for문 다돌았는데 문제 없으면
	return true;
}
