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

void Tour(int sizey, int sizex, Point pos, Point *direction, int **boardt); // �迭������, ���� ������, ������ ����, 2�����迭

int main() {
	int T;
	cin >> T;
	for (int TC = 0; TC < T; TC++) {
		int y, x, n; // ��, ��, ����
		cin >> y >> x >> n;
		int **arr = new int*[y];
		for (int i = 0; i < y; i++) {
			arr[i] = new int[x];
		}
		// 0���� �ʱ�ȭ
		for (int i = 0; i < y; i++)
			for (int j = 0; j < x; j++)
				arr[i][j] = 0;

		// ������ �ִ� ��ǥ�� �Է¹ޱ�
		for (int i = 0; i < n; i++) {
			int yy, xx;
			cin >> yy >> xx;
			arr[yy][xx] = 1;
		}
		Point dir[4];
		dir[0].setXY(-1, 0); dir[1].setXY(0, -1); dir[2].setXY(1, 0); dir[3].setXY(0, 1);
		Point start; // ������ġ
		int sx, sy; // x�� ������ġ, y�� ������ġ
		int cnt = 0; // �̾��� �ִ� ������ ũ��
		for (int i = 0; i < y; i++) {
			for (int j = 0; j < x; j++) {
				if (arr[i][j] == 1) { // 0�̶�� ���������� start
					sy = i;
					sx = j;
					start.setY(sy);
					start.setX(sx);
					Tour(y, x, start, dir, arr);
					cnt++;
				}
			}
		}

		//// �׽�Ʈ ��¹�
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
	for (int i = 0; i < 4; i++) { // �̵��� �� �ִ� ����� ���� 4���� �̹Ƿ�
		next.setX(pos.getX() + direction[i].getX());
		next.setY(pos.getY() + direction[i].getY());
		if (next.getX() >= 0 && next.getX() < sizex && next.getY() >= 0 && next.getY() < sizey && board[next.getY()][next.getX()] == 1) { // �迭�� ���� �̵���ġ�� 1�� ���¶��
			board[next.getY()][next.getX()] = MARK; // ���ٴ� ǥ�� ����
			Tour(sizey, sizex, next, direction, board);
		}
	}
}