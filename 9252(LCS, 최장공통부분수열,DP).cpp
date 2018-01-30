#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>

using namespace std;

void dpLCS(vector<vector<int>>&lcsDpTable, vector<char>a, vector<char>b);
void printlcsDpTable(vector<vector<int>>lcsDpTable); // 테스트용 출력함수
int main() {
	vector<char>a, b;
	string stringA, stringB;
	getline(cin, stringA);
	getline(cin, stringB);
	a.push_back('x'); // 일단 0번째 주소에 아무거나 넣는다
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
	// 초기에 0 집어넣기
	for (int i = 0; i < lcsDpTable.size(); i++) {
		for (int j = 0; j < lcsDpTable[i].size(); j++) {
			if (i == 0) lcsDpTable[0][j] = 0;
			if (j == 0) lcsDpTable[i][0] = 0;
		}
	}
	// b.size() = lcsDpTable.size() , a.size() = lcsDpTable[i].size() 이다. string b가 열(ㅣ)의 데이터이고 string a가 행(ㅡ)의 데이터이다.
	for (int i = 1; i < b.size(); i++) {
		for (int j = 1; j < a.size(); j++) {
			if (b[i] == a[j])  // 문자열이 일치하면
				lcsDpTable[i][j] = lcsDpTable[i - 1][j - 1] + 1; // 전까지 비교했던 거에서 +1을 해준다.
			else // 문자열이 일치 안하면
				lcsDpTable[i][j] = max(lcsDpTable[i - 1][j], lcsDpTable[i][j - 1]); // 전에 했던거중 큰걸 뽑는다.
		}
	}
	int maxNum; // 최장공통부분수열의 갯수
	maxNum = lcsDpTable[lcsDpTable.size() - 1][lcsDpTable[lcsDpTable.size() - 1].size() - 1];
	cout << maxNum << endl;
	// 이제 그 문자열을 구해야한다. 위에서 왔을수도 왼쪽에서 왔을수도 대각선에서 왔을수도 있는데 대각선에서 왔을 때 출력을 해주면 된다. (UP:1, LEFT:2, UP:3)
	vector<vector<int>>check;
	check = lcsDpTable; // 복사하지만 어짜피 나중에 다시 채워짐 UP, LEFT, UP으로 크기만 일단 복사하는거임
	for (int i = 1; i < b.size(); i++) {
		for (int j = 1; j < a.size(); j++) {
			if (b[i] == a[j])  // 문자열이 일치하면 a나 b에서 아무거나 출력하면된다.
				check[i][j] = 3;
			else {
				if (max(lcsDpTable[i - 1][j], lcsDpTable[i][j - 1]) == lcsDpTable[i - 1][j]) // 위에서 온 경우
					check[i][j] = 1;
				else // 왼쪽에서 온 경우
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
	// 거꾸로 찾아간다. (앞에서 넣어야 출력을 똑바로 했을때 제대로 나옴) 3(대각에서 왔을때)일때 저장해주면됨
	deque<char>result;
	int y = b.size() - 1, x = a.size() - 1; // 시작지점은 맨 오른쪽 아래
	while (check[y][x] != 0) { // 0이면 다 찾은거니 break임
		if (check[y][x] == 3) { // 대각에서 왔을 때
			result.push_front(b[y]); // == result.push_front(a[x]);   대각이니 앞으로 넣어준거임
			y--;
			x--; // 왼쪽위로 찾는지점 바꿔준다.
		}
		else if (check[y][x] == 2)  // 왼쪽에서 왔을 때
			x--;
		else if (check[y][x] == 1) // 위에서 왔을 때
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
