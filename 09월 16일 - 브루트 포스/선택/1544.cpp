#include<iostream>
#include<set>
using namespace std;

bool isCycle(set<string>& s, string str) {
	int cnt = str.length();

	while (cnt--) {
		// 같은 단어가 있는 경우
		if (s.find(str) != s.end()) {
			return true;
		}

		// 시계 방향대로, 앞 글자를 떼어서 뒤에 붙여줌.
		str = str + str[0];
		str.erase(0, 1);
	}
	return false;
}
int main() {
	int n;
	string str;
	set<string> word; // 단어 저장

	// 입력
	cin >> n;
	while (n--) {
		cin >> str;

		// 같은 단어 없으면 추가
		if (!isCycle(word, str)) {
			word.insert(str);
		}
	}

	// 출력
	cout << word.size();
}