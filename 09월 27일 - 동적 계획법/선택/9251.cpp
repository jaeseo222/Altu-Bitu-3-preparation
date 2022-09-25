#include <iostream>
#include <vector>

using namespace std;

/*
 * LCS 점화식
 * 1) 두 문자가 같은 경우 : dp[i][j] = dp[i][j] + 1
 * 2) 두 문자가 다른 경우 : dp[i][j] = max(dp[i-1][j], dp[i][j-1])
 */

int LCS(string str1, string str2) {
    int n = str1.length();
    int m = str2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i < n + 1; i++) { //인덱스 관리를 위해 1부터 시작
        for (int j = 1; j < m + 1; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}

int main() {
    string a, b;
    //입력
    cin >> a >> b;

    //연산, 출력
    cout << LCS(a, b);

    return 0;
}