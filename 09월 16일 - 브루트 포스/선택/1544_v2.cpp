#include<iostream>
#include<vector>
using namespace std;

bool isCycle(string a, string b) {
	for (int i = 0; i < a.size(); i++) {
		// 같은 단어일 경우
		if (a == b) return true;

		// 시계 방향대로, 앞 글자를 떼어서 뒤에 붙여줌.
		a = a + a[0];
		a.erase(0, 1);
	}
	return false;
}
int main() {
	int n;
	string str;
	vector<string> word; // 단어 저장

	// 입력
	cin >> n;
	while (n--) {
		cin >> str;

		bool flag = false;
		for (int i = 0; i < word.size(); i++) {
			// 단어의 길이 확인
			if (word[i].length() != str.length()) {
				continue;
			}

			if (isCycle(word[i], str)) {
				flag = true;
				break;
			}
		}
		// 같은 단어 없으면 추가
		if (!flag) {
			word.push_back(str);
		}
	}

	// 출력
	cout << word.size();
}