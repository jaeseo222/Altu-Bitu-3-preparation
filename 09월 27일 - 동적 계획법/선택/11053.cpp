#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 시간 복잡도 O(n^2)
int solution(int n, vector<int> &arr) {
    vector<int> dp(n, 1);
    int ans = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) { //증가하는 관계라면
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]); //최장 길이 갱신
    }
    return ans;
}


int main() {
    int n;

    //입력
    cin >> n;
    vector<int> arr(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    //연산 & 출력
    cout << solution(n, arr);

}
