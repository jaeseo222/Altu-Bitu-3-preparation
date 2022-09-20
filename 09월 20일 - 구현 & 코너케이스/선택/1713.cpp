#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
typedef pair<int, int> ci;
/*
  * map 컨테이너를 활용하여 각 후보에 <후보 번호, 추천 횟수>를 페어로 저장하고 바로 접근
  * 1. 비어있는 사진틀이 없는 경우 후보를 삭제
  * -> min_element() 함수로 추천수가 가장 적은 학생, 추천수가 같다면 게시 시간이 오래된 학생 찾기
  * -> min_element(x.begin(), x.end(), cmp): x 컨테이너 내에서 최솟값을 찾아주는 함수로 sort 함수와 비슷하게 cmp 함수로 조건 설정 가능
  * 2. 후보를 처음 게시하는 경우에만 게시 시간 기록
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
	map<int, ci> candidate; // first: 후보 번호, second: {추천 횟수, 게시 시간}
	// 연산
	for (int i = 0; i < m; i++) {
		cin >> input;
		//비어있는 사진틀이 없는 경우
		if (candidate.size() == n && candidate.find(input) == candidate.end()) {
			candidate.erase(min_element(candidate.begin(), candidate.end(), cmp)); // 후보 삭제
		}
		//후보 첫 게시
		if (candidate.find(input) == candidate.end()) {
			candidate[input].second = i; // 게시 시간 기록
		}
		candidate[input].first++; //추천 횟수 증가
	}
	// 출력
	for (auto iter = candidate.begin(); iter != candidate.end(); iter++) {
		cout << iter->first << ' ';
	}
	return 0;
}
