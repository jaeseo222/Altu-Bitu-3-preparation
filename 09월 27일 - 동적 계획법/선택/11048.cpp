#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
* 동적프로그래밍을 이용하여 값을 업데이트
* 첫 행과 열은 따로 처리
*/

int maxCandy(int n, int m, vector<vector<int>>dp)
{
	// 첫 번째 열
	for (int i = 1; i < n; i++) {
		dp[i][0] += dp[i - 1][0];
	}
	// 첫 번째 행
	for (int i = 1; i < m; i++) {
		dp[0][i] += dp[0][i - 1];
	}
	// 나머지 부분
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			dp[i][j] += max({ dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1] }); // 가장 큰 값으로 업데이트
		}
	}
	return dp[n - 1][m - 1];
}

int main()
{
	// 입력
	int n, m;
	cin >> n >> m;
	vector<vector<int>> maze(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> maze[i][j];
		}
	}
	// 연산 & 출력
	cout << maxCandy(n, m, maze); 
	return 0;
}
