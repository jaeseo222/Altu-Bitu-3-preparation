#include <iostream>
#include <set>
using namespace std;

string str;
set<string> s;

void makeNum(int left, int right, string path) {
	// 더 이상 좌우로 이동할 곳이 없을 경우
	if (left == 0 && right == str.length() - 1) {
		s.insert(path);
		return;
	}

	// 검사 범위 체크
	if (left > 0) {
		// 왼쪽에 숫자를 하나 적는 과정
		makeNum(left - 1, right, path + str[left - 1] + path);
	}
	if (right < str.length() - 1) {
		// 오른쪽에 숫자를 하나 적는 과정
		makeNum(left, right + 1, path + path + str[right + 1]);
	}
}
/*
* [N으로 만들기]
* - 어떤 수 N을 만들기 위해, 아래 두 가지 행동 반복
*	1. 수의 왼쪽에 숫자를 하나 적는다.
*	2. 수의 오른쪽에 숫자를 하나 적는다.
*
* - 숫자를 적는 과정에서 나온 수가 순서대로 모두 같다면 같은 방법이다.
* -> 숫자를 적는 과정을 string으로 연결하여 저장 후 set으로 중복 체크
*/
int main() {
	// 입력
	cin >> str;

	// 계산
	for (int i = 0; i < str.length(); i++) {
		string tmp = "";
		makeNum(i, i, tmp + str[i]);
	}

	// 출력
	cout << s.size();
}