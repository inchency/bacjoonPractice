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
	getline(cin, temp); // 쓰레기 공백 temp에 일단 받고
	for (int i = 0; i < num; i++) 
		getline(cin, passWord[i], '\n');
	for (int i = 0; i < num; i++) {
		stack <char> buffer; // 스택형 임시 버퍼
		for (int j = i; j < num; j++) {
			while (!buffer.empty()) buffer.pop(); // 초기화
			for (int k = 0; k < passWord[i].size(); k++) {
				buffer.push(passWord[i][k]);
			}
			bool flag = true; // 초기값은 참이라 가정
			// 일단 길이 비교
			if (buffer.size() == passWord[j].size()) { // 길이 같으면 뒤집은 단어랑 같을 희망이 있음
				for (int k = 0; k < passWord[j].length(); k++) {
					if (buffer.top() == passWord[j][k]) { // stack의 top과 비교해나가면서 같으면 pop
						buffer.pop();
						continue;
					}
					else {
						flag = false;
						break; // 더 이상 비교할 가치 x
					}
				}
				if (flag) { // 끝까지 참이라면
					cout << passWord[j].size() << " " << passWord[j][passWord[j].length()/2]; // 길이와 가운데 문자 출력
				}
			}
			else { // 길이부터 다르면
				continue; // 다음꺼 비교
			}
		}
	}
	
	
	return 0;
}