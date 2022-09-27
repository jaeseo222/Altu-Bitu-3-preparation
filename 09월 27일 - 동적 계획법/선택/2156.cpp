#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//최대로 마실 수 있는 포도주 양을 구하는 함수
int maxWine(int n, vector<int> wine) {
	vector<int> dp(n+1, 0);
	//더미 인덱스 사용하여 예외 처리
	dp[1] = wine[0];
	dp[2] = wine[0] + wine[1];

	//max() 함수 사용 시 3개 이상의 값 비교시 {}로 묶으면 한 번에 사용 가능합니다!
	for (int i = 3; i < n+1; i++) {
		//가장 큰 값으로 갱신
		dp[i] = max({ dp[i - 4] + wine[i - 2] + wine[i-1],dp[i - 3] + wine[i-1],dp[i - 2] });
	}
	return dp[n];
}
int main() {
	int n;
	
	cin >> n;
	vector<int> wine(n+1);
	

	for (int i = 1; i < n+1; i++) {
		cin >> wine[i];
	}

	cout << maxWine(n, wine);
}
