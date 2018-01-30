#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#define MAX 100010

using namespace std;

int prim(vector<vector<int>>arr, vector<bool>visited);

int main() {
	int V, E;
	cin >> V >> E;
	vector<vector<int>>arr;
	for (int i = 0; i < V + 1; i++) {
		vector<int>elements(V + 1);
		arr.push_back(elements);
	}
	vector<bool>visited;
	for (int i = 0; i < V + 1; i++) {
		visited.push_back(false);
	}

	for (int i = 0; i < E; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		arr[A][B] = C;
		arr[B][A] = C;
	}

	for (int i = 0; i < arr.size(); i++)
		for (int j = 0; j < arr[i].size(); j++)
			if (arr[i][j] == NULL)
				arr[i][j] = MAX;

	/*for (int i = 0; i < arr.size(); i++) {
	for (int j = 0; j < arr[i].size(); j++) {
	cout << arr[i][j] << " ";
	}
	cout << endl;
	}
	cout << endl;*/
	/*for (int i = 0; i < visited.size(); i++) {
	cout << visited[i] << " ";
	}*/

	cout << prim(arr, visited);

	return 0;
}

int prim(vector<vector<int>>arr, vector<bool>visited) {
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq; // top이 가장 작은 수 3, 1, 2 넣으면 1 2 3 이런식으로 저장되겠지?
	int result = 0;
	visited[1] = true; // 임의로 1부터 시작
	bool checkVisitedAllTrue = false;
	while (!checkVisitedAllTrue) { // 모든 visited가 true이면 break
		for (int i = 1; i < visited.size(); i++) {
			if (visited[i]) { // 지나간 점들이면 비교할 가치가 있는 대상들
				for (int j = 1; j < arr[i].size(); j++) {
					if (!visited[j] && arr[i][j] != MAX) {
						pq.push(make_pair(arr[i][j], j)); // pair의 first 값은 간선의 길이고 second 값은 그 간선에서 해당하는 정점으로 가는 점V이다.
					}
				}
			}
		}
		int min = pq.top().first;
		int minIndex = pq.top().second;
		result += min;
		while (!pq.empty()) pq.pop(); // 우선순위큐 초기화 시키기
		visited[minIndex] = true;
		checkVisitedAllTrue = true;
		for (int k = 1; k < visited.size(); k++) {
			if (!visited[k]) {
				checkVisitedAllTrue = false;
				break;
			}
		}
	}
	return result;
}