#include <iostream>
using namespace std;
#define MARK 2

class Point {
private:
	int x, y;
public:
	void setXY(int x, int y) {
		this->x = x;
		this->y = y;
	}
	void setX(int x) {
		this->x = x;
	}
	void setY(int y) {
		this->y = y;
	}
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
};

void Tour(int sizey, int sizex, Point pos, Point *direction, int **boardt); // 배열사이즈, 비교할 시작점, 움직일 방향, 2차원배열

int main() {
	int T;
	cin >> T;
	for (int TC = 0; TC < T; TC++) {
		int y, x, n; // 행, 열, 갯수
		cin >> y >> x >> n;
		int **arr = new int*[y];
		for (int i = 0; i < y; i++) {
			arr[i] = new int[x];
		}
		// 0으로 초기화
		for (int i = 0; i < y; i++)
			for (int j = 0; j < x; j++)
				arr[i][j] = 0;

		// 지렁이 있는 좌표값 입력받기
		for (int i = 0; i < n; i++) {
			int yy, xx;
			cin >> yy >> xx;
			arr[yy][xx] = 1;
		}
		Point dir[4];
		dir[0].setXY(-1, 0); dir[1].setXY(0, -1); dir[2].setXY(1, 0); dir[3].setXY(0, 1);
		Point start; // 시작위치
		int sx, sy; // x축 시작위치, y축 시작위치
		int cnt = 0; // 이어져 있는 배추의 크기
		for (int i = 0; i < y; i++) {
			for (int j = 0; j < x; j++) {
				if (arr[i][j] == 1) { // 0이라면 그지점부터 start
					sy = i;
					sx = j;
					start.setY(sy);
					start.setX(sx);
					Tour(y, x, start, dir, arr);
					cnt++;
				}
			}
		}

		//// 테스트 출력문
		//for (int i = 0; i < y; i++) {
		//	for (int j = 0; j < x; j++) {
		//		cout << arr[i][j] << " ";
		//	}
		//	cout << endl;
		//}
		cout << cnt << endl;
	}
	return 0;
}

void Tour(int sizey, int sizex, Point pos, Point *direction, int **board) {
	Point next;
	for (int i = 0; i < 4; i++) { // 이동할 수 있는 경우의 수가 4가지 이므로
		next.setX(pos.getX() + direction[i].getX());
		next.setY(pos.getY() + direction[i].getY());
		if (next.getX() >= 0 && next.getX() < sizex && next.getY() >= 0 && next.getY() < sizey && board[next.getY()][next.getX()] == 1) { // 배열판 내의 이동위치며 1의 상태라면
			board[next.getY()][next.getX()] = MARK; // 갔다는 표시 해줌
			Tour(sizey, sizex, next, direction, board);
		}
	}
}