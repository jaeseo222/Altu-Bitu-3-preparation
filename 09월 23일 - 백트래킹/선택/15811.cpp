#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;

//재귀에서는 지역변수를 활용한다면 매 함수마다 매개변수로 값을 넘겨주어 불필요한 메모리 낭비가 일어날 수도 있기에 전역변수로 선언해요!

vector<int> store_used_alphabet;//사용된 알파벳을 저장할 벡터 -> 
vector<string> words(3);
vector<pair<bool,int>> alphabet_to_number(26, make_pair(false, -1));//<알파벳 사용여부, 할당된 숫자>
vector<bool> used_number(10, false);//숫자 사용 여부

long long wordToNumber(string word) {//word를 숫자로 바꾸는 함수
	long long num = 0;
	for (int i = 0; i < word.length(); i++) {
		num = num * 10 + alphabet_to_number[word[i] - 'A'].second;
	}
	return num;
}

bool calc() {//답이 존재하는지 여부를 판단하는 함수
	vector<long long> number(3);//word를 숫자로 바꾼 결과를 저장할 벡터

	for (int i = 0; i < 3; i++) {
		number[i] = wordToNumber(words[i]);
	}

	if (number[0] + number[1] == number[2]) {
		return true;
	}
	return false;
}

void checkUsedAlphabet(string word) {//알파벳을 숫자로 바꾼 결과를 저장하는 벡터와 사용된 알파벳을 저장하는 벡터 만드는 함수
	for (int i = 0; i < word.length(); i++) {

		if (!alphabet_to_number[word[i] - 'A'].first) {//알파벳이 나온적이 없다면
			alphabet_to_number[word[i] - 'A'].first = true;
			store_used_alphabet.push_back(word[i] - 'A');
		}
		
	}
}

void backtracking(int level) {

	if (level == store_used_alphabet.size()) {//한번의 bactracking마다 알파벳 하나에 숫자가 할당되므로 store_used_alphabet벡터의 사이즈와 bactracking의 level이 같으면 모든 알파벳에 숫자가 할당된 것
		if (calc()) {
			cout << "YES";
			exit(0);
		}

	}

	for (int i = 0; i < 10; i++) {//알파벳에 차례로 숫자 할당
		if (!used_number[i]) {

			used_number[i] = true;
			alphabet_to_number[store_used_alphabet[level]].second = i;

			backtracking(level + 1);

			used_number[i] = false;
			alphabet_to_number[store_used_alphabet[level]].second = -1;

		}
	}
}

/*
* 1. main에서 단어를 입력받아 checkUsedAlphabet함수로 사용된 알파벳 체크
* 2. backtrackig함수로 알파벳에 차례로 숫자를 할당하고
* 3. 모든 알파벳에 숫자가 할당 되었을 때
* 4. calc 함수로 복면산 조건을 만족하는지 확인 -> 조건을 만족하면 YES 출력하고 종료
*/
int main() {

	for (int i = 0; i < 3; i++) {
		cin >> words[i];
		checkUsedAlphabet(words[i]);//입력받은 단어에 사용된 알파벳 체크
	}
	
	if (store_used_alphabet.size() > 10) {//알파벳 종류가 10개 초과면 
		cout << "NO";
		return 0;
	}

	backtracking(0);

	cout << "NO";

	return 0;
}