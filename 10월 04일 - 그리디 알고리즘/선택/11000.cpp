#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> ci;

/*
* 강의를 시작 시간이 빠른 순서로 정렬
* 우선순위 큐를 사용하여 강의 종료 시간을 빠른 순서로 정렬
* 같은 강의실에서 다음 수업을 진행하는 경우 가장 종료 시간이 빠른 강의를 pop하고 새로운 종료 시간을 push
*/

int schedule(vector<ci> lecture)
{
	priority_queue<int, vector<int>, greater<>> pq; // 강의 종료 시간을 우선순위 큐에 저장
	pq.push(lecture[0].second); // 첫 수업의 강의 종료 시간 저장
	for (int i = 1; i < lecture.size(); i++) {
		if (pq.top() <= lecture[i].first) { // 수업이 끝난 직후 다음 수업 시작 (같은 강의실)
			pq.pop(); 
		}
		pq.push(lecture[i].second); // 새로운 강의실
	}
	return pq.size(); // 총 강의실 수
}

int main()
{
	int n;
	// 입력
	cin >> n;
	vector<ci> v(n, {0, 0});
	for (int i = 0; i < n; i++){
		cin >> v[i].first >> v[i].second;
	}
	// 연산 & 출력
	sort(v.begin(), v.end()); // 강의를 시작 시간 순서로 정렬
	cout << schedule(v) << '\n'; // 최소로 필요한 강의실 수 계산
	return 0;
}
