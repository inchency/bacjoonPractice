#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
	int cases;
	cin >> cases;
	vector <int> parent(cases + 1); // +1 하는 이유는 0도 포함시킬려고
	stack<pair<int, int>> temp1; // 순서 때문에 parent에 못채우는 거 임시로 stack에 (first, second) pair (쌍으로) 저장시켜둠
	stack<pair<int, int>> temp2; // 부모 또 못찾을 수도 있으니 하나 더
	parent[1] = 1; // root = 1
	for (int i = 1; i < cases; i++) {
		int a, b;
		cin >> a >> b;
		if (parent[a] != NULL) { // 첫번째 수 a가 부모를 이미 가지고 있으면
			parent[b] = a; // b의 부모는 a
		}
		else if (parent[b] != NULL) { // a가 부모가 없고 두번째 수 b가 부모를 가지고 있으면
			parent[a] = b;
		}
		else { // 둘다 부모 없으면
			temp1.push({ a, b }); // pair로 stack에 저장
		}
	}
	while (!temp1.empty() || !temp2.empty()) {
		// 이제 부모 못 찾은 것들을 다시 찾아준다.
		while (!temp1.empty()) {
			int a, b;
			a = temp1.top().first;
			b = temp1.top().second;
			if (parent[a] != NULL) { // 첫번째 수 a가 부모를 이미 가지고 있으면
				parent[b] = a; // b의 부모는 a
			}
			else if (parent[b] != NULL) { // a가 부모가 없고 두번째 수 b가 부모를 가지고 있으면
				parent[a] = b;
			}
			else { // 이번에도 둘다 부모 없으면
				temp2.push({ a, b }); // pair로 temp2 stack에 저장
			}
			temp1.pop();
		}
		// 이제 부모 못 찾은 것들을 다시 찾아준다.
		while (!temp2.empty()) {
			int a, b;
			a = temp2.top().first;
			b = temp2.top().second;
			if (parent[a] != NULL) { // 첫번째 수 a가 부모를 이미 가지고 있으면
				parent[b] = a; // b의 부모는 a
			}
			else if (parent[b] != NULL) { // a가 부모가 없고 두번째 수 b가 부모를 가지고 있으면
				parent[a] = b;
			}
			else { // 이번에도 둘다 부모 없으면
				temp1.push({ a, b }); // pair로 temp2 stack에 저장
			}
			temp2.pop();
		}
	}
	for (int i = 2; i < cases; i++)
		cout << parent[i] << "\n";
	/*for (int i = 2; i <= cases; i++) {
		printf("%d\n", parent[i]);
	}*/
	/*
	// 출력
	for (int i = 2; i <= cases; i++) {
		cout << parent[i] << endl;
	}
	*/
	return 0;
}