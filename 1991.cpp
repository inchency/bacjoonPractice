#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
	char name; // 노드이름
	Node *left; // 왼쪽자식
	Node *right; // 오른쪽자식
	Node(char name) {
		this->name = name;
		left = NULL;
		right = NULL;
	}
	friend class List;
};

class List {
public:
	Node *head;
	List() { head = NULL; }
	void insert(char parent, char leftChild, char rightChild); // 노드 삽입
	void preorderSearch(Node *p); // 전위 탐색
	void inorderSearch(Node *p); // 중위 탐색
	void postorderSearch(Node *p); // 후위 탐색
	void search(Node *p, char data, Node *lc, Node *rc); // insert 할 때 필요
	bool isEmpty(); // 노드가 1개도 없을 때
};

int main() {
	int num;
	cin >> num;
	vector<vector<char>>arr;
	for (int i = 0; i < num; i++) {
		vector<char>element(3);
		arr.push_back(element);
	}
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}
	List tree;
	for (int i = 0; i < num; i++) {
		tree.insert(arr[i][0], arr[i][1], arr[i][2]);
	}
	tree.preorderSearch(tree.head);
	cout << endl;
	tree.inorderSearch(tree.head);
	cout << endl;
	tree.postorderSearch(tree.head);
	/*for (int i = 0; i < num; i++) {
		for (int j = 0; j < 3; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}*/

	return 0;
}

void List::search(Node *p, char data, Node *lc, Node *rc) { // 전위방식으로 탐색 p가 해당 노드
	if (p == NULL) return;
	if (p->name == data) {
		p->left = lc;
		p->right = rc;
		return;
	}
	search(p->left, data, lc, rc); // 왼쪽 찾고
	search(p->right, data, lc, rc);
}

void List::insert(char parent, char leftChild, char rightChild) {
	Node *p;
	Node *par = new Node(parent);
	Node *lc = new Node(leftChild);
	Node *rc = new Node(rightChild);
	if (isEmpty()) { // 첫 노드 일 때
		head = par;
		par->left = lc;
		par->right = rc;
	}
	else { // 첫 노드 아니면
		p = head;
		search(p, parent, lc, rc);
	}
}

void List::preorderSearch(Node *p) {
	if (p == NULL) return; // 빈 노드 일 때까지
	if (p->name != '.')
		cout << p->name; // 부모노드 출력
	preorderSearch(p->left); // 왼쪽자식노드 출력
	preorderSearch(p->right); // 오른쪽자식노드 출력
}
void List::inorderSearch(Node *p) {
	if (p == NULL) return;
	inorderSearch(p->left);
	if (p->name != '.')
		cout << p->name; // 부모노드 출력
	inorderSearch(p->right);
}
void List::postorderSearch(Node *p) {
	if (p == NULL) return;
	postorderSearch(p->left);
	postorderSearch(p->right);
	if (p->name != '.')
		cout << p->name; // 부모노드 출력
}

bool List::isEmpty() {
	if (head == NULL)
		return true;
	else
		return false;
}