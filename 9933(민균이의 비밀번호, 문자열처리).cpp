#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
using namespace std;

int main() {
	int num;
	cin >> num;
	vector<string>passWord(num);
	string temp;
	getline(cin, temp); // ������ ���� temp�� �ϴ� �ް�
	for (int i = 0; i < num; i++) 
		getline(cin, passWord[i], '\n');
	for (int i = 0; i < num; i++) {
		stack <char> buffer; // ������ �ӽ� ����
		for (int j = i; j < num; j++) {
			while (!buffer.empty()) buffer.pop(); // �ʱ�ȭ
			for (int k = 0; k < passWord[i].size(); k++) {
				buffer.push(passWord[i][k]);
			}
			bool flag = true; // �ʱⰪ�� ���̶� ����
			// �ϴ� ���� ��
			if (buffer.size() == passWord[j].size()) { // ���� ������ ������ �ܾ�� ���� ����� ����
				for (int k = 0; k < passWord[j].length(); k++) {
					if (buffer.top() == passWord[j][k]) { // stack�� top�� ���س����鼭 ������ pop
						buffer.pop();
						continue;
					}
					else {
						flag = false;
						break; // �� �̻� ���� ��ġ x
					}
				}
				if (flag) { // ������ ���̶��
					cout << passWord[j].size() << " " << passWord[j][passWord[j].length()/2]; // ���̿� ��� ���� ���
				}
			}
			else { // ���̺��� �ٸ���
				continue; // ������ ��
			}
		}
	}
	
	
	return 0;
}