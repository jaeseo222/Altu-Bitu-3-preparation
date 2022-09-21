#include<iostream>
#include<vector>
using namespace std;

int calc(int n, vector<int> arr, int total) {
	vector<int> dp(total + 1, 0);

	// 초기화
	dp[0] = 1;

	for (int i = 0; i < n; i++) {
		for (int j = arr[i]; j <= total; j++) {
			dp[j] += dp[j - arr[i]];
		}
	}
	return dp[total];
}
/*
* [동전]
* N가지 동전의 각 금액이 오름차순으로 정렬되어 주어짐.
* 적은 금액의 동전부터, M원을 만들 수 있는 방법의 수를 누적하여 세야 함.
*
* - dp[i] : i원을 만들 수 있는 방법의 수
* - 각 동전의 맨 처음 경우(예를 들어, 21원짜리 동전으로 21원을 만들 경우), 반드시 한 개는 만들 수 있음.
*	-> 처음으로 동전을 사용하기 위해, 동전을 쓰지 않은 상태를 초기화 해야 함.
*	-> 따라서, dp[0]을 1로 초기화
*/
int main() {
	int t, n, total;

	// 입력
	cin >> t;
	while (t--) {
		cin >> n;

		vector<int>  coin(n);
		for (int i = 0; i < n; i++) {
			cin >> coin[i];
		}

		// 계산 & 출력
		cin >> total;
		cout << calc(n, coin, total) << "\n";
	}
}