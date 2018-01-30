#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Node {
private:
	int num;
	Node *left;
	Node *right;
	friend class BST;
public:
	Node(int num) {
		this->num = num;
	}
	int setNum() {
		return num;
	}
};

class BST {
private:
	Node *root;
public:
	Node *getRoot() {
		return root;
	}
	BST() {
		this->root = NULL;
	}
	void insert(int num) {
		Node *temp = new Node(num);
		if (root == NULL) {
			root = temp;
		}
		else {
			Node *p = root;
			Node *q = NULL;
			int flag = 0; // 0 은 일치 1은 왼쪽 2는 오른쪽으로 간것
			while (p != NULL) {
				if (p->setNum() == num) {
					flag = 0;
					break;
				}
				else if (p->setNum() > num) {
					q = p;
					p = p->left;
					flag = 1;
				}
				else {
					q = p;
					p = p->right;
					flag = 2;
				}
			}
			if (flag == 1) {
				Node *temp = new Node(num);
				p = temp;
				q->left = p;
			}
			else if (flag == 2) {
				Node *temp = new Node(num);
				p = temp;
				q->right = p;
			}
		}
	}
	void postOrderPrint(Node *p) {
		if (p != NULL) {
			postOrderPrint(p->left);
			postOrderPrint(p->right);
			printf("%d\n", p->setNum());
		}
	}
};

int main() {
	BST bst;
	int num;
	while (scanf("%d", &num) != EOF) {
		bst.insert(num);
	}
	bst.postOrderPrint(bst.getRoot());
	return 0;
}
