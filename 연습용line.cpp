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
	시간복잡도 : O(n) (상수배 무시)
	공간복잡도 : O(n) (상수배 무시) (q, tempStack 총 두개의 stack이 쓰임)
	*/

	int dequeue() {
		// TODO implement your codes to here.
		stack<int>tempStack;
		int result;
		while (q.size() >= 1) { // 마지막 하나만 남을 때 까지
			if (q.size() == 1) {
				result = q.top();
				q.pop();
			}
			else {
				tempStack.push(q.top()); // pop 하기전에 q.top()을 push한다.
				q.pop();
			}
		}
		// tempStack에는 데이터가 반대로 들어가 있는 상태이기 때문에 다시 바꿔주는 작업을 해야한다.
		int tempStackSize = tempStack.size(); // size가 변하니까 변수를 하나 만든다.
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
