#include<iostream>
#include<queue>
#include<cmath>
using namespace std;

int attack(priority_queue<int>& q, int h, int t) {
	int cnt = 0;
	while (cnt < t) {
		int tmp = q.top();
		if (tmp < h || tmp == 1) {
			break;
		}
		cnt++;
		q.pop();
		q.push(floor(tmp / 2));
	}
	return cnt;
}

/*
* [센티와 마법의 뿅망치]
*
* 가장 키가 큰 거인 가운데 하나를 때리기 위해
* 내림차순 우선순위 큐 사용
*/
int main() {
	priority_queue<int> q;
	int n, h, t, height;

	// 입력
	cin >> n >> h >> t;

	while (n--) {
		cin >> height;
		q.push(height);
	}

	// 계산
	int cnt = attack(q, h, t);

	// 출력
	if (q.top() < h) {
		cout << "YES\n" << cnt;
	}
	else {
		cout << "NO\n" << q.top();
	}
}