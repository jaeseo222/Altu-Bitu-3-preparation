#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> ci;
/*
  * <후보 번호, 추천 횟수>를 페어로 벡터(candidate)에 게시되는 사진속 후보를 저장
  * 벡터에 후보를 하나씩 추가 (후보가 게시 시간 순서대로 배열됨)
*/

bool currCandidate(vector<ci> &v, int input)
{
	for (auto it = v.begin(); it != v.end(); it++)
	{
		if (it->first == input) {
			it->second++; // 추천 횟수 증가
			return true;
		}
	}
	return false;
}

void delCandidate(vector<ci> &v)
{
	int min_candidate = 1000;
	// 가장 적게 추천된 후보의 추천 수 구하기
	for (int i = 0; i < v.size(); i++) {
		min_candidate = min(min_candidate, v[i].second);
	}
	// 추천 수가 가장 적고, 가장 오래된 사진을 삭제 
	for (int i = 0; i < v.size(); i++) {
		if (v[i].second == min_candidate) {
			v.erase(v.begin() + i);
			break;
		}
	}
}

int main()
{
	int n, m, input;
	// 입력
	cin >> n >> m;
	vector<ci> v; // 후보 번호, 추천 횟수 (게시 시간은 vector의 순서와 일치)
	// 연산
	while (m--)
	{
		cin >> input;
		// 이미 게시된 후보인지 확인
		if (currCandidate(v, input)) {
			continue;
		}
		// 비어있는 사진틀이 없는 경우 사진 삭제
		if (v.size() == n) {
			delCandidate(v);
		}
		// 새로 후보 사진 게시
		v.push_back({ input, 1 });
	}
	// 출력
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
		cout << v[i].first << ' ';
}
