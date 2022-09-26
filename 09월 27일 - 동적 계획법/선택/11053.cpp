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
// 더 다양한 풀이방법 (아래 링크 참조)
// https://github.com/Altu-Bitu-2/Notice/blob/main/03%EC%9B%94%2029%EC%9D%BC%20-%20%EB%8F%99%EC%A0%81%20%EA%B3%84%ED%9A%8D%EB%B2%95/%EA%B3%BC%EC%A0%9C/11053.cpp 

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
