#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAX = 26;
/*
* [단어 수학]
*
* 각 알파벳 대문자를 0부터 9까지의 숫자 중 하나로 바꿔서 N개의 수를 합하는 문제
* -> 어떤 알파벳을 높은 수로 바꿔줘야 할까?
* -> 각 알파벳마다의 자리수를 합하여, 합한 수가 높을수록 높은 수로 바꿔줌.
*
* 1. 각 자리수에 온 알파벳마다 합을 구함
* 2. 알파벳을 숫자로 바꾸었을 때 합을 최대로 만들기 위해, 내림차순 정렬
* 3. 9부터 곱하여 더함
*
* => 알파벳의 순서가 중요해 보이나, 중요하지 않은 문제
*/
int main() {
	int n, ans = 0;
	string str;

	// 입력
	cin >> n;

	// 각 알파벳마다의 합을 구하기 위해 0으로 초기화
	vector<int> alphabet(MAX, 0);

	// 입력 & 계산
	while (n--) {
		cin >> str;

		int len = str.size();
		for (int i = 0; i < len; i++) {
			alphabet[str[i] - 'A'] += pow(10, len - i - 1);
		}
	}

	// 내림차순 정렬
	sort(alphabet.begin(), alphabet.end(), greater<>());

	// 0부터 9까지의 숫자 중 하나로 바꾸니까, 어차피 나올 수 있는 수는 0 ~ 9
	for (int i = 0; i <= 9; i++) {
		ans += alphabet[i] * (9 - i);
	}

	cout << ans;
}