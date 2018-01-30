#include <iostream>
#include <string>
using namespace std;

class Stack {
private:
	int *stack_ary;
	int top;
	int size;
public:
	Stack(int size);
	void stack_del();
	void push(int data);
	int pop();
	void print_size();
	void print_top();
	int is_empty();
	bool is_full();
};
// 스택 초기화
Stack::Stack(int size) {
	stack_ary = new int[size];
	this->size = size;
	top = -1;
}
// 스택 메모리해제
void Stack::stack_del() {
	delete stack_ary;
}
// 꽉찼는지 확인
bool Stack::is_full() {
	if (this->size <= top) {
		return true; // 꽉참
	}
	return false; // 꽉 안참
}
// 비었는지 확인
int Stack::is_empty() {
	if (top == -1)
		return 1; // 빔
	return 0; // 안 빔
}
// push
void Stack::push(int data) {
	if (is_full()) cout << "꽉차서 못넣음" << endl;
	else stack_ary[++top] = data;
}
// pop
int Stack::pop() {
	if (is_empty()) return -1;
	return stack_ary[top--];
}
// size 출력
void Stack::print_size() {
	cout << this->top + 1 << endl;
}
void Stack::print_top() {
	if (is_empty()) cout << "-1" << endl;
	else cout << stack_ary[top] << endl;
}

int main() {
	int n, num;
	string command;
	cin >> n;
	Stack s(n);
	for (int cases = 0; cases < n; cases++) {
		cin >> command;
		if (!command.compare("push")) {
			cin >> num;
			s.push(num);
			continue;
		}
		if (!command.compare("pop")) cout << s.pop() << endl;
		else if (!command.compare("size")) s.print_size();
		else if (!command.compare("empty")) cout << s.is_empty() << endl;
		else if (!command.compare("top")) s.print_top();
		else cout << "잘못입력함 다시 ㄱ" << endl;
		
	}
	s.stack_del();
	return 0;
}