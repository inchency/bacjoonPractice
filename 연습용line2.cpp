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
	// E는 넣을수 있는 주유량, C는 소모되는 기름량
	int s = E.size(); // 주유소 갯수
	int ESum, CSum, cnt, index; // 각각의 합
	for (int z = 0; z < s; z++) { // z=0 0번지의 index부터 탐색을 할거임
		ESum = 0, CSum = 0; // 각각의 합 초기화
		cnt = 0; // 인덱스 넘어가는 경우도 있음
		index = z; // z로 초기화
		bool flag = false; // 무사히 마치면 falg = true 로 변함
		while (cnt <= s) { // cnt가 갯수보다 작을 때 까지
			if (index == s) { // z의 인덱스가 마지막을 넘어 다음꺼에 왔다면
				index = 0; // index를 0으로 초기화 (다시 처음으로 순환이므로)
			}
			ESum += E[index];
			CSum += C[index];
			if (ESum < CSum) 
				break; // 안되는 케이스므로 while 루프를 빠져나가 다음 index로 넘어간다.
			if (cnt == s)
				flag = true; // 마지막까지 판별했는데 가능하면 그것이 정답인 index (최소부터 시작함)
			index++;
			cnt++;
		}
		if (flag) return z; // z의 인덱스를 반환
	}
	return -1; // 만약 가능한 경우의 수가 없으면 -1을 반환
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
