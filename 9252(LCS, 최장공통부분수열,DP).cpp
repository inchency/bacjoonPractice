#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>

using namespace std;

void dpLCS(vector<vector<int>>&lcsDpTable, vector<char>a, vector<char>b);
void printlcsDpTable(vector<vector<int>>lcsDpTable); // �׽�Ʈ�� ����Լ�
int main() {
	vector<char>a, b;
	string stringA, stringB;
	getline(cin, stringA);
	getline(cin, stringB);
	a.push_back('x'); // �ϴ� 0��° �ּҿ� �ƹ��ų� �ִ´�
	b.push_back('x');
	for (int i = 0; i < stringA.size(); i++)
		a.push_back(stringA[i]);
	for (int i = 0; i < stringB.size(); i++)
		b.push_back(stringB[i]);
	vector<vector<int>>lcsDpTable(b.size());
	for (int i = 0; i < lcsDpTable.size(); i++) {
		vector<int>contents(a.size());
		lcsDpTable[i]=contents;
	}
	dpLCS(lcsDpTable, a, b);
	//printlcsDpTable(lcsDpTable);
	return 0;
}

void dpLCS(vector<vector<int>>&lcsDpTable, vector<char>a, vector<char>b) {
	// �ʱ⿡ 0 ����ֱ�
	for (int i = 0; i < lcsDpTable.size(); i++) {
		for (int j = 0; j < lcsDpTable[i].size(); j++) {
			if (i == 0) lcsDpTable[0][j] = 0;
			if (j == 0) lcsDpTable[i][0] = 0;
		}
	}
	// b.size() = lcsDpTable.size() , a.size() = lcsDpTable[i].size() �̴�. string b�� ��(��)�� �������̰� string a�� ��(��)�� �������̴�.
	for (int i = 1; i < b.size(); i++) {
		for (int j = 1; j < a.size(); j++) {
			if (b[i] == a[j])  // ���ڿ��� ��ġ�ϸ�
				lcsDpTable[i][j] = lcsDpTable[i - 1][j - 1] + 1; // ������ ���ߴ� �ſ��� +1�� ���ش�.
			else // ���ڿ��� ��ġ ���ϸ�
				lcsDpTable[i][j] = max(lcsDpTable[i - 1][j], lcsDpTable[i][j - 1]); // ���� �ߴ����� ū�� �̴´�.
		}
	}
	int maxNum; // �������κм����� ����
	maxNum = lcsDpTable[lcsDpTable.size() - 1][lcsDpTable[lcsDpTable.size() - 1].size() - 1];
	cout << maxNum << endl;
	// ���� �� ���ڿ��� ���ؾ��Ѵ�. ������ �������� ���ʿ��� �������� �밢������ �������� �ִµ� �밢������ ���� �� ����� ���ָ� �ȴ�. (UP:1, LEFT:2, UP:3)
	vector<vector<int>>check;
	check = lcsDpTable; // ���������� ��¥�� ���߿� �ٽ� ä���� UP, LEFT, UP���� ũ�⸸ �ϴ� �����ϴ°���
	for (int i = 1; i < b.size(); i++) {
		for (int j = 1; j < a.size(); j++) {
			if (b[i] == a[j])  // ���ڿ��� ��ġ�ϸ� a�� b���� �ƹ��ų� ����ϸ�ȴ�.
				check[i][j] = 3;
			else {
				if (max(lcsDpTable[i - 1][j], lcsDpTable[i][j - 1]) == lcsDpTable[i - 1][j]) // ������ �� ���
					check[i][j] = 1;
				else // ���ʿ��� �� ���
					check[i][j] = 2;
			}
		}
	}
	/*for (int i = 0; i < b.size(); i++) {
		for (int j = 0; j < a.size(); j++) {
			cout << check[i][j] << " ";
		}
		cout << endl;
	}*/
	// �Ųٷ� ã�ư���. (�տ��� �־�� ����� �ȹٷ� ������ ����� ����) 3(�밢���� ������)�϶� �������ָ��
	deque<char>result;
	int y = b.size() - 1, x = a.size() - 1; // ���������� �� ������ �Ʒ�
	while (check[y][x] != 0) { // 0�̸� �� ã���Ŵ� break��
		if (check[y][x] == 3) { // �밢���� ���� ��
			result.push_front(b[y]); // == result.push_front(a[x]);   �밢�̴� ������ �־��ذ���
			y--;
			x--; // �������� ã������ �ٲ��ش�.
		}
		else if (check[y][x] == 2)  // ���ʿ��� ���� ��
			x--;
		else if (check[y][x] == 1) // ������ ���� ��
			y--;
	}
	for (int i = 0; i < result.size(); i++)
		cout << result[i];
}

void printlcsDpTable(vector<vector<int>>lcsDpTable) {
	for (int i = 0; i < lcsDpTable.size(); i++) {
		for (int j = 0; j < lcsDpTable[i].size(); j++) {
			cout << lcsDpTable[i][j] << " ";
		}
		cout << endl;
	}
}
