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
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq; // top�� ���� ���� �� 3, 1, 2 ������ 1 2 3 �̷������� ����ǰ���?
	int result = 0;
	visited[1] = true; // ���Ƿ� 1���� ����
	bool checkVisitedAllTrue = false;
	while (!checkVisitedAllTrue) { // ��� visited�� true�̸� break
		for (int i = 1; i < visited.size(); i++) {
			if (visited[i]) { // ������ �����̸� ���� ��ġ�� �ִ� ����
				for (int j = 1; j < arr[i].size(); j++) {
					if (!visited[j] && arr[i][j] != MAX) {
						pq.push(make_pair(arr[i][j], j)); // pair�� first ���� ������ ���̰� second ���� �� �������� �ش��ϴ� �������� ���� ��V�̴�.
					}
				}
			}
		}
		int min = pq.top().first;
		int minIndex = pq.top().second;
		result += min;
		while (!pq.empty()) pq.pop(); // �켱����ť �ʱ�ȭ ��Ű��
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