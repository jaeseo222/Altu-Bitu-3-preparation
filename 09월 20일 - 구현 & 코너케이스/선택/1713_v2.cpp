#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
typedef pair<int, int> ci;
/*
  * map을 활용하여 각 후보에 <후보 번호, 추천 횟수>를 페어로 저장
  * 1. 이미 게시된 후보라면 추천 횟수 증가
  * 2. 비어있는 사진틀이 없는 경우 후보를 삭제 (cmp의 규칙에 따라서)
  * 3. 새로 후보 사진 게시
*/

bool cmp(const pair<int, ci>& c1, const pair<int, ci>& c2) {
	if (c1.second.first != c2.second.first) { // 추천 횟수가 다를 경우
		return c1.second.first < c2.second.first;
	}
	return c1.second.second < c2.second.second;
}

int main()
{
	int n, m, input;
	// 입력
	cin >> n >> m;
	map<int, ci> candidate; // first: 후보 번호, second: (추천 횟수, 게시 시간)
	// 연산
	for(int i = 0; i<m; i++) {
		cin >> input;
		// 이미 게시된 후보인지 확인
		if (candidate.find(input) != candidate.end()) {
			candidate[input].first++; // 추천 횟수 증가
			continue;
		}
		// 비어있는 사진틀이 없는 경우 사진 삭제
		if (candidate.size() == n) {
			candidate.erase(min_element(candidate.begin(), candidate.end(), cmp)); // 후보 삭제
		}
		// 새로 후보 사진 게시
		candidate[input].first++; // 추천 횟수 증가
		candidate[input].second = i; // 게시 시간 저장
	}
	// 출력
	for (auto iter = candidate.begin(); iter != candidate.end(); iter++) {
		cout << iter->first << ' ';
	}
	return 0;
}
