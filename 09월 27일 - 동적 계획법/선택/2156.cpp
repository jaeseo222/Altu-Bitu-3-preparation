#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxWine(int n, vector<int> wine) {
	vector<int> dp(n, 0);
	dp[0] = wine[0];
	
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