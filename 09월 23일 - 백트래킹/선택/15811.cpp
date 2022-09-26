#include<iostream>
#include<vector>
#include<string>
using namespace std;

//재귀에서는 지역변수를 활용한다면 매 함수마다 매개변수로 값을 넘겨주어 불필요한 메모리 낭비가 일어날 수도 있기에 전역변수로 선언해요!

vector<int> store_used_alphabet;//사용된 알파벳을 저장할 벡터
vector<string> words(3);
vector<int> alphabet_to_number(26, -1);
vector<bool> used_number(10, false);

long long wordToNumber(string &word) {//word를 숫자로 바꾸는 함수
	long long num = 0;
	for (int i = 0; i < word.length(); i++) {
		num = num * 10 + alphabet_to_number[word[i] - 'A'];
	}
	return num;
}

void checkUsedAlphabet() {//알파벳을 숫자로 바꾼 결과를 저장하는 벡터와 사용된 알파벳을 저장하는 벡터 만드는 함수
	vector<bool> check_used_alphabet(26,false);

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < words[i].length(); j++) {

			if (!check_used_alphabet[words[i][j] - 'A']) {
				check_used_alphabet[words[i][j] - 'A'] = true;
				store_used_alphabet.push_back(words[i][j] - 'A');
			}

		}
	}
}

bool backtracking(int cnt) {
	bool ans = false;//(생각해보기)백트래킹 탐색의 과정에서 해당 변수가 꼭 필요한 이유가 무엇일까요?!

	if (cnt == store_used_alphabet.size()) {//한번의 bactracking마다 알파벳 하나에 숫자가 할당되므로 store_used_alphabet 벡터의 사이즈와 bactracking의 level이 같으면 모든 알파벳에 숫자가 할당된 것
		if (wordToNumber(words[0]) + wordToNumber(words[1]) == wordToNumber(words[2])) {
			return true;
		}
		return false;
	}

	for (int i = 0; i < 10; i++) {//알파벳에 차례로 숫자 할당
		if (!used_number[i]) {

			used_number[i] = true;
			alphabet_to_number[store_used_alphabet[cnt]] = i;

			ans =backtracking(cnt + 1);
			if (ans) {
				return true;
			}

			used_number[i] = false;
			alphabet_to_number[store_used_alphabet[cnt]] = -1;

		}
	}
	return ans;
}

/*
* 1. main에서 단어를 입력받아 checkUsedAlphabet함수로 사용된 알파벳 체크
* 2. backtrackig함수로 알파벳에 차례로 숫자를 할당하고
* 3. 모든 알파벳에 숫자가 할당 되었을 때
* 4. 복면산 조건을 만족하는지 확인 -> 조건을 만족하면 YES 출력하고 종료
*/
int main() {

	for (int i = 0; i < 3; i++) {
		cin >> words[i];
	}
	checkUsedAlphabet();

	cout << (backtracking(0) ? "YES" : "NO");

	return 0;
}
