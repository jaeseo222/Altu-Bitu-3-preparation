/*
* 특정 조건을 만족하고(모든 사람이 심사를 받는다) 최소값을 구하는 형식 -> 파라미터 탐색,.,??
* 모든 사람이 심사를 받는다는 조건을 만족한다는 것을 어떻게 표현,,,,???
*/

/*
* 처음에 time 만들 때 int로 하고 계산할 때 쓰는 값 mid 랑 people만 long long 으로 했더니 실패함
* 찾아보니까 위에처럼 자료형 막 다르게 하면 오버플로우 ㄴ누ㅡㄴ...? 걍 다 long long으로 했더니 성공...라라랄
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;



long long parametricSearch(long long left, long long right, int n, int m,vector<long long>& time) {

	long long answer = 0;

	while (left <= right) {

		long long mid = (left + right)/2;
		long long people = 0;

		for (int i = 0; i < n; i++) {
			people += mid / time[i];
		}

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
	vector<long long> time(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> time[i];
	}
	sort(time.begin(), time.end());
	
	long long max_time = time[n-1] * m;
	cout << parametricSearch(1, max_time, n, m, time);
	
	return 0;
}