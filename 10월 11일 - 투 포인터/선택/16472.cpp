#include <iostream>
#include <vector>

using namespace std;
const int MAX = 26;

int translate(int n, string str) {
	vector<int> alphabet(MAX);
	int cnt = 0, ans = 0;
	int left = 0, right = 0;

	while (left <= right && right < str.length()) {
		int idx = str[right++] - 'a';
		alphabet[idx]++;
		if (alphabet[idx] == 1) {
			cnt++; // 인식할 수 있는 알파벳 종류가 되어서, 개수 증가
		}

		// 최대 길이 갱신할 지, left 이동할 지 결정
		if (cnt <= n) {
			ans = max(ans, right - left);
		}
		else {
			idx = str[left++] - 'a';
			alphabet[idx]--;
			if (alphabet[idx] == 0) {
				cnt--;  // 인식 못하는 알파벳 종류가 되어서, 개수 감소
			}
		}
	}
	return ans;
}
/*
* [고냥이]
*
* 1. 번역기가 인식할 수 있는 문자열의 최대'길이'를 구해야 함.
*	 -> 구간 내의 모든 문자를 고려하기 때문에 한쪽에서 시작하는 투 포인터
* 2. 각 문자는 알파벳 소문자이기 때문에 배열로 등장 횟수 체크할 수 있음
* 3. 일단 right를 움직이고, 현재 인식할 수 있는 상태인지 확인
*	 -> (인식할 수 있는 알파벳 종류 최대 개수보다 현재 인식하고 있는 종류 개수가 적거나 같아서) 현재 인식할 수 있는 상태이면, 최대 길이 갱신
*	 -> 아니면, left를 움직이면서 길이 유지
*
* ? 일단 right를 움직여도 되는 이유 ?
* => 예를 들어, 현재 인식할 수 있는 최대 길이가 5로 갱신된 상태일 때, right를 움직인 후
*	 길이 5 내에서 인식을 못하면 어차피 최대 길이로 갱신을 못하기 때문에 left를 움직여줌.
*	 결국, 길이 5를 유지하면서 움직이다가, 인식할 수 있는 상태가 되면 최대 길이로 갱신
*/
int main() {
	int n;
	string str;

	// 입력
	cin >> n >> str;

	// 출력 & 계산
	cout << translate(n, str);
}