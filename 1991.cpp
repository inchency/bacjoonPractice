#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
	char name; // ����̸�
	Node *left; // �����ڽ�
	Node *right; // �������ڽ�
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
	void insert(char parent, char leftChild, char rightChild); // ��� ����
	void preorderSearch(Node *p); // ���� Ž��
	void inorderSearch(Node *p); // ���� Ž��
	void postorderSearch(Node *p); // ���� Ž��
	void search(Node *p, char data, Node *lc, Node *rc); // insert �� �� �ʿ�
	bool isEmpty(); // ��尡 1���� ���� ��
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

void List::search(Node *p, char data, Node *lc, Node *rc) { // ����������� Ž�� p�� �ش� ���
	if (p == NULL) return;
	if (p->name == data) {
		p->left = lc;
		p->right = rc;
		return;
	}
	search(p->left, data, lc, rc); // ���� ã��
	search(p->right, data, lc, rc);
}

void List::insert(char parent, char leftChild, char rightChild) {
	Node *p;
	Node *par = new Node(parent);
	Node *lc = new Node(leftChild);
	Node *rc = new Node(rightChild);
	if (isEmpty()) { // ù ��� �� ��
		head = par;
		par->left = lc;
		par->right = rc;
	}
	else { // ù ��� �ƴϸ�
		p = head;
		search(p, parent, lc, rc);
	}
}

void List::preorderSearch(Node *p) {
	if (p == NULL) return; // �� ��� �� ������
	if (p->name != '.')
		cout << p->name; // �θ��� ���
	preorderSearch(p->left); // �����ڽĳ�� ���
	preorderSearch(p->right); // �������ڽĳ�� ���
}
void List::inorderSearch(Node *p) {
	if (p == NULL) return;
	inorderSearch(p->left);
	if (p->name != '.')
		cout << p->name; // �θ��� ���
	inorderSearch(p->right);
}
void List::postorderSearch(Node *p) {
	if (p == NULL) return;
	postorderSearch(p->left);
	postorderSearch(p->right);
	if (p->name != '.')
		cout << p->name; // �θ��� ���
}

bool List::isEmpty() {
	if (head == NULL)
		return true;
	else
		return false;
}