#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>
#include <algorithm> 
#include <iterator> 

using namespace std;

class set {
public:
	vector<int>make; // 세트의 벡터
	bool flag = false; // 사용하지 않은 세트
};

int main() {
	string num;
	getline(cin, num, '\n'); // 한줄 문자열로 입력받기
	vector <int> roomNum(num.length()); // 문자열 길이만큼 roomNum 벡터 생성
	
	for (int i = 0; i < num.length(); i++) {
		// roomNum[i] = num[i] - '0' ; // 숫자로 배열에 넣기 (아래꺼도 연습)
		roomNum[i] = atoi(num.substr(i,1).c_str()); //c_str이 string -> char*로 변환해주고 다시 이걸 atoi를 써서 int형으로 변환해줌.. numsubstr(i,i+1)은 해당 한 글자만!!
	}

	set *s = new set[num.length()];
	// 최대 num.length() 만큼의 세트가 필요함 최악의 경우
	for (int i = 0; i < num.length(); i++) {
		for (int j = 0; j < 10; j++) {
			s[i].make.push_back(j);
		}
	}

	for (int i = 0; i < num.length(); i++) {
		vector<int>::iterator iter;
		for (int j = 0; j < num.length();) {
			iter = find(s[j].make.begin(), s[j].make.end(), roomNum[i]); // 해당 방 번호 찾기 시작
			if (iter == s[j].make.end()) { // 해당 세트에서 없으면
				if (roomNum[i] == 6) { // 근데 6이면
					vector<int>::iterator iter2;
					iter2 = find(s[j].make.begin(), s[j].make.end(), 9); // 9인거를 한번 더 찾는다.
					if (iter2 == s[j].make.end()) { // 근데도 없으면
						j++;
						continue; // 다음 세트에서 찾는다
					}
					else { // 있으면
						s[j].make.erase(iter2); // remove와 find의 차이 remove는 하면 뒤에 컨테이너가 유지됨.. 9로 쌓임 단 erase는 아예 삭제됨 size가 변함
						//s[j].make.erase(remove(s[j].make.begin(), s[j].make.end(), 9), s[j].make.end()); // 6대신 9 삭제 (여기서 remove가 반환하는 값은 remove 된 후의 무효한 영역의 시작위치)
						break;
					}
				}
				else if (roomNum[i] == 9) { // 근데 9이면
					vector<int>::iterator iter2;
					iter2 = find(s[j].make.begin(), s[j].make.end(), 6); // 6인거를 한번 더 찾는다.
					if (iter2 == s[j].make.end()) { // 근데도 없으면
						j++;
						continue;
					}
					else { // 있으면
						s[j].make.erase(iter2); // 즉 find한 위치가 iter2니까 그 자리를 삭제하는 것임
						//s[j].make.erase(remove(s[j].make.begin(), s[j].make.end(), 6), s[j].make.end()); // 9대신 6 삭제
						break;
					}
				}
				else {  // 6이나 9 아닐 때
					j++;
				}
			}
			else { // 해당 세트에서 있으면
				s[j].make.erase(iter);
				//vector<int>::iterator iter2;
				//iter2 = remove(s[j].make.begin(), s[j].make.end(), roomNum[i]), s[j].make.end();
				//remove(s[j].make.begin(), s[j].make.end(), roomNum[i]); // 해당 값 세트에서 삭제
				/*for (int k = 0; k < s[j].make.size(); k++) {
					cout << s[j].make[k] << " ";
				}*/
				//cout << endl;
				s[j].flag = true; // 이 세트는 썼다는 표시 해줌
				break;
			}
		}
	}
	// flag 갯수를 세어 true인거 찾으면 됨
	int res = 0;
	for (int i = 0; i < num.length(); i++) {
		if (s[i].flag == true) res++;
	}
	cout << res;
	return 0;
}