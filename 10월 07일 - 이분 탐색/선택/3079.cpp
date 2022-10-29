/*
* 특정 조건을 만족하고(모든 사람이 심사를 받는다) 최소값을 구하는 형식 -> 파라미터 탐색
*/

#include <iostream>
#include <algorithm>
#include <vector>
typedef long long ll;
using namespace std;

ll calPeople(int n, ll mid, vector<ll>& time) {
	ll people = 0;
	for (int i = 0; i < n; i++) {//시간(mid)안에 검사받을 수 있는 사람 수 구하기
		if (mid < time[i]) {//time이 정렬 -> 이후 시간에 검사받을 수 있는 사람 수는 0
			break;
		}
		people += mid / time[i];
	}
	return people;
}

ll parametricSearch(ll left, ll right, int n, int m,vector<ll>& time) {

	ll answer = 0;

	while (left <= right) {

		ll mid = (left + right)/2;
		ll people = calPeople(n, mid, time);

		//범위 조정
		if (people < m) {
			left = mid + 1;
		}
		else {
			answer = mid;
			right = mid - 1;
		}
		
	}
	return answer;
}

int main(void) {
	int n, m;
	cin >> n >> m;
	vector<ll> time(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> time[i];
	}
	sort(time.begin(), time.end());

	ll max_time = time[n - 1] * m;//최대로 걸리는 시간 : 가장 오래 걸리는 심사대에서 모든 사람이 심사 받는 시간
	cout << parametricSearch(1, max_time, n, m, time);
	
	return 0;
}
