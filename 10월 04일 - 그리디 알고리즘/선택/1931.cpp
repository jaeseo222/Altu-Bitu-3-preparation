#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> ci;
/*
* 회의의 시작 시간과 끝나는 시간을 pair로 저장
* 끝나는 시간이 빠른 회의, 끝나는 시간이 같은 경우 시작 시간이 빠른 회의 순서로 정렬
* 현재 시간보다 회의 시작 시간이 크거나 같으면 회의 추가, 현재 시간을 회의가 끝나는 시간으로 업데이트
*/
bool cmp(const ci& m1, const ci& m2)
{
	if (m1.second != m2.second) { // 회의가 끝나는 시간이 같은 경우
		return m1.second < m2.second;
	}
	return m1.first < m2.first;
}

int schedule(vector<ci> m) 
{
	int cnt = 0, curr = 0; // cnt: 회의 회수, curr: 현재 시간
	sort(m.begin(), m.end(), cmp);
	for (auto iter = m.begin(); iter != m.end(); iter++) {
		if (iter->first >= curr) { // 회의 추가
			curr = iter->second;
			cnt++;
		}
	}
	return cnt;
}

int main()
{
	int n;
	// 입력
	cin >> n;
	vector<ci> meeting;
	int start, end;
	while (n--) {
		cin >> start >> end;
		meeting.push_back({ start, end });
	}
	// 연산 & 출력
	cout << schedule(meeting);
	return 0;
}
