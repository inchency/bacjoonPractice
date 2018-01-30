#include <iostream>
#include <string>
#include <stack>
using namespace std;
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
////// BEGIN OF EDIT AREA.
/////////////////////////////////////////////////////////////////////////

//Please use `stack` class only
class Queue {
public:
	/*
	* Description:
	* Time complexity:
	* Space complexity:
	*/
	stack<int>q;
	void enqueue(int v) {
		// TODO implement your codes to here.
		q.push(v);
	}

	/*
	�ð����⵵ : O(n) (����� ����)
	�������⵵ : O(n) (����� ����) (q, tempStack �� �ΰ��� stack�� ����)
	*/

	int dequeue() {
		// TODO implement your codes to here.
		stack<int>tempStack;
		int result;
		while (q.size() >= 1) { // ������ �ϳ��� ���� �� ����
			if (q.size() == 1) {
				result = q.top();
				q.pop();
			}
			else {
				tempStack.push(q.top()); // pop �ϱ����� q.top()�� push�Ѵ�.
				q.pop();
			}
		}
		// tempStack���� �����Ͱ� �ݴ�� �� �ִ� �����̱� ������ �ٽ� �ٲ��ִ� �۾��� �ؾ��Ѵ�.
		int tempStackSize = tempStack.size(); // size�� ���ϴϱ� ������ �ϳ� �����.
		for (int i = 0; i < tempStackSize; i++) {
			q.push(tempStack.top());
			tempStack.pop();
		}
		return result;
	}
};

/////////////////////////////////////////////////////////////////////////
////// END OF EDIT AREA.
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
int main(int argc, const char *argv[]) {
	Queue queue;
	string command;
	int count, value;
	cin >> count;
	for (int i = 0; i < count; ++i) {
		cin >> command;
		if (command == "ENQUEUE") {
			cin >> value;
			queue.enqueue(value);
		}
		else if (command == "DEQUEUE") {
			cout << queue.dequeue() << endl;
		}
	}
}
