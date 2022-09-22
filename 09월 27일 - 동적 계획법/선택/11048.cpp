#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
* 동적프로그래밍을 이용하여 값을 업데이트
* 더미 인덱스를 사용하여 예외 없이 한 번에 처리
*/

int maxCandy(int n, int m, vector<vector<int>>dp)
{
	// 동적 계획법으로 사탕의 개수 계산
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] += max({ dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1] }); // 가장 큰 값으로 업데이트
		}
	}
	return dp[n][m];
}

int main()
{
	// 입력
	int n, m;
	cin >> n >> m;
	vector<vector<int>> maze(n+1, vector<int>(m+1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> maze[i][j];
		}
	}
	// 연산 & 출력
	cout << maxCandy(n, m, maze);
	return 0;
}
