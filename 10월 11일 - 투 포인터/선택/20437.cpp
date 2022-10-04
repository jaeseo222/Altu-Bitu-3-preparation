#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;
typedef pair<int, int> ci;
/*
* 각 문자의 인덱스를 맵에 저장하고 인덱스를 활용하여 문자열의 길이 계산 (포인터가 인덱스를 가르키도록)
* 1. 어떤 문자 K개를 포함하는 가장 짧은 연속 문자열의 길이 -> min 함수로 계산
* 2. 어떤 문자 K개를 포함하고 처음과 끝이 해당 문자인 가장 긴 연속 문자열의 길이 -> max 함수로 계산
*/

pair<int, int> game(string w, int k)
{
	map<char, vector<int>> char_idx;
	int str_short = w.size(), str_long = -1;
	for (int i = 0; i < w.size(); i++) { // 맵에 문자의 인덱스 저장
		char_idx[w[i]].push_back(i);
	}
	for (auto iter = char_idx.begin(); iter != char_idx.end(); iter++) { // 각 문자를 포함하는 문자열 확인
		int n = (iter->second).size();
		if (n >= k) { // 문자의 개수가 k개 이상인 경우만 확인
			int left = 0, right = k - 1; // 포인터 초기화
			while (right < n) {
				str_short = min(str_short, iter->second[right] - iter->second[left] + 1); // 1번 문자열
				str_long = max(str_long, iter->second[right] - iter->second[left] + 1); // 2번 문자열
				left++;
				right++;
			}
		}
	}
	return { str_short, str_long };
}

int main()
{
	int t, k;
	string w;
	// 입력
	cin >> t;
	while (t--) {
		cin >> w >> k;
		// 연산
		pair<int, int> ans = game(w, k);
		// 출력
		if (ans.second == -1) // 만족하는 문자열이 없는 경우
			cout << -1 << '\n';
		else
			cout << ans.first << " " << ans.second << '\n';
	}
	return 0;
}
