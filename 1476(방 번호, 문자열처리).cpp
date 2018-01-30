#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>
#include <algorithm> 
#include <iterator> 

using namespace std;

class set {
public:
	vector<int>make; // ��Ʈ�� ����
	bool flag = false; // ������� ���� ��Ʈ
};

int main() {
	string num;
	getline(cin, num, '\n'); // ���� ���ڿ��� �Է¹ޱ�
	vector <int> roomNum(num.length()); // ���ڿ� ���̸�ŭ roomNum ���� ����
	
	for (int i = 0; i < num.length(); i++) {
		// roomNum[i] = num[i] - '0' ; // ���ڷ� �迭�� �ֱ� (�Ʒ����� ����)
		roomNum[i] = atoi(num.substr(i,1).c_str()); //c_str�� string -> char*�� ��ȯ���ְ� �ٽ� �̰� atoi�� �Ἥ int������ ��ȯ����.. numsubstr(i,i+1)�� �ش� �� ���ڸ�!!
	}

	set *s = new set[num.length()];
	// �ִ� num.length() ��ŭ�� ��Ʈ�� �ʿ��� �־��� ���
	for (int i = 0; i < num.length(); i++) {
		for (int j = 0; j < 10; j++) {
			s[i].make.push_back(j);
		}
	}

	for (int i = 0; i < num.length(); i++) {
		vector<int>::iterator iter;
		for (int j = 0; j < num.length();) {
			iter = find(s[j].make.begin(), s[j].make.end(), roomNum[i]); // �ش� �� ��ȣ ã�� ����
			if (iter == s[j].make.end()) { // �ش� ��Ʈ���� ������
				if (roomNum[i] == 6) { // �ٵ� 6�̸�
					vector<int>::iterator iter2;
					iter2 = find(s[j].make.begin(), s[j].make.end(), 9); // 9�ΰŸ� �ѹ� �� ã�´�.
					if (iter2 == s[j].make.end()) { // �ٵ��� ������
						j++;
						continue; // ���� ��Ʈ���� ã�´�
					}
					else { // ������
						s[j].make.erase(iter2); // remove�� find�� ���� remove�� �ϸ� �ڿ� �����̳ʰ� ������.. 9�� ���� �� erase�� �ƿ� ������ size�� ����
						//s[j].make.erase(remove(s[j].make.begin(), s[j].make.end(), 9), s[j].make.end()); // 6��� 9 ���� (���⼭ remove�� ��ȯ�ϴ� ���� remove �� ���� ��ȿ�� ������ ������ġ)
						break;
					}
				}
				else if (roomNum[i] == 9) { // �ٵ� 9�̸�
					vector<int>::iterator iter2;
					iter2 = find(s[j].make.begin(), s[j].make.end(), 6); // 6�ΰŸ� �ѹ� �� ã�´�.
					if (iter2 == s[j].make.end()) { // �ٵ��� ������
						j++;
						continue;
					}
					else { // ������
						s[j].make.erase(iter2); // �� find�� ��ġ�� iter2�ϱ� �� �ڸ��� �����ϴ� ����
						//s[j].make.erase(remove(s[j].make.begin(), s[j].make.end(), 6), s[j].make.end()); // 9��� 6 ����
						break;
					}
				}
				else {  // 6�̳� 9 �ƴ� ��
					j++;
				}
			}
			else { // �ش� ��Ʈ���� ������
				s[j].make.erase(iter);
				//vector<int>::iterator iter2;
				//iter2 = remove(s[j].make.begin(), s[j].make.end(), roomNum[i]), s[j].make.end();
				//remove(s[j].make.begin(), s[j].make.end(), roomNum[i]); // �ش� �� ��Ʈ���� ����
				/*for (int k = 0; k < s[j].make.size(); k++) {
					cout << s[j].make[k] << " ";
				}*/
				//cout << endl;
				s[j].flag = true; // �� ��Ʈ�� ��ٴ� ǥ�� ����
				break;
			}
		}
	}
	// flag ������ ���� true�ΰ� ã���� ��
	int res = 0;
	for (int i = 0; i < num.length(); i++) {
		if (s[i].flag == true) res++;
	}
	cout << res;
	return 0;
}