#include<iostream>
#include<vector>
using namespace std;

int knapsack(int n, vector<int> arr, int m) {
	vector<int> dp(m + 1, 0);

	// 초기화
	dp[0] = 1;

	for (int i = 0; i < n; i++) {
		for (int j = arr[i]; j <= m; j++) {
			dp[j] += dp[j - arr[i]];
		}
	}
	return dp[m];
}
/*
* [동전]
* N가지 동전의 각 금액이 오름차순으로 정렬되어 주어짐.
* 적은 금액의 동전부터, M원을 만들 수 있는 방법의 수를 누적하여 세야 함.
*
* dp[i] : i원을 만들 수 있는 방법의 수
*
* dp[0] = 1 을 넣고 시작 (0원을 만드는 경우의 수 1로 생각)
* 각 동전마다 해당 동전부터 만들어야 하는 금액(m)까지 돌리면서 해당 동전을 사용하기 전 금액의 경우의 수와 현재 경우의 수를 더함
* 해당 동전 사용하기 전 금액의 경우의 수가 0이면 금액을 만들 수 없는 경우이지만, 어차피 더해도 값 변화는 없으므로 따로 고려하지 않음
*/
int main() {
	int t, n, m;

	// 입력
	cin >> t;
	while (t--) {
		cin >> n;

		vector<int>  coin(n);
		for (int i = 0; i < n; i++) {
			cin >> coin[i];
		}

		// 계산 & 출력
		cin >> m;
		cout << knapsack(n, coin, m) << "\n";
	}
}