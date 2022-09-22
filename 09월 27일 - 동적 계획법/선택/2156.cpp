#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//최대로 마실 수 있는 포도주 양을 구하는 함수
int maxWine(int n, vector<int> wine) {
	vector<int> dp(n, 0);
	dp[0] = wine[0];
	
	/*
	입력이 3 이하일 경우는 for문 안에 넣어서 check
	max() 함수 사용 시 3개 이상의 값 비교시 {}로 묶으면 한 번에 사용 가능합니다!
	*/
	
	for (int i = 1; i < n; i++) {
		if (i < 2) {
			dp[1] = wine[0] + wine[1];
			continue;
		}
		if (i < 3) {
			dp[2] = max({ wine[1] + wine[2], wine[0] + wine[2], dp[1] });
			continue;
		}
		dp[i] = max({ dp[i - 3] + wine[i - 1] + wine[i],dp[i - 2] + wine[i],dp[i - 1] });
	}
	return dp[n - 1];
}
int main() {
	int n;
	
	cin >> n;
	vector<int> wine(n);
	

	for (int i = 0; i < n; i++) {
		cin >> wine[i];
	}

	cout << maxWine(n, wine);
}
