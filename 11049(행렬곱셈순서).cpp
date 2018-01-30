#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp(vector<pair<int, int>> & vp);

int main() {
	int cases;
	scanf("%d", &cases);
	vector<pair<int, int>>vp;
	vp.push_back(make_pair(0, 0)); // 쓰레기값 집어넣기
	for (int testCases = 0; testCases < cases; testCases++) {
		int a, b;
		cin >> a >> b;
		vp.push_back(make_pair(a, b));
		//cout << vp[testCases].first << " " << vp[testCases].second << endl;
	}
	cout << dp(vp);
	return 0;
}

int dp(vector<pair<int, int>> & vp) {
	int size = vp.size();
	vector<vector<int>> dpTable;
	for (int i = 0; i < size; i++) {
		vector<int>element(size);
		dpTable.push_back(element);
	}
	// dpTable 초기화
	for (int i = 1; i < size; i++)
		dpTable[i][i] = 0;
	for (int j = 2; j < size; j++) {
		int indexY = j;
		int indexX = 1;
		for (int i = j; i < size; i++) {
			if (j == 2)
				dpTable[indexX][indexY] = vp[indexX].first * vp[indexX].second * vp[indexY].second;

			else {
				vector<int> findMin;
				for (int k = indexX + 1; k < indexY - 1; k++) {
					findMin.push_back(dpTable[indexX][k] + dpTable[k + 1][indexY] + vp[indexX].first * vp[k].second * vp[indexY].second);
				}
				findMin.push_back(min(dpTable[indexX][indexY - 1] + vp[indexX].first * vp[indexY - 1].second * vp[indexY].second, dpTable[indexX + 1][indexY] + vp[indexX + 1].first * vp[indexY].second * vp[indexX].first));
				dpTable[indexX][indexY] = *min_element(findMin.begin(), findMin.end());
			}
				//dpTable[indexX][indexY] = min(dpTable[indexX][indexY - 1] + vp[indexX].first * vp[indexY - 1].second * vp[indexY].second, dpTable[indexX + 1][indexY] + vp[indexX + 1].first * vp[indexY].second * vp[indexX].first);
			//cout << dpTable[indexX][indexY] << endl;
			indexX++;
			indexY++;
		}
	}

	for (int i = 1; i < size; i++) {
		for (int j = 1; j < size; j++) {
			cout << dpTable[i][j] << " ";
		}
		cout << endl;
	}
	return dpTable[1][size - 1];
}