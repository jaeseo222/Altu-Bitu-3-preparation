#include <iostream>
#define MAX 100010
using namespace std;

int solution(int n, int m, int k, int prefix_sum[]) {
    int answer = 0;
    for (int i = 1; i <= n; i++) {
        int s = i, e = (i + m - 1) % n;
        int sum = 0;
        if (e < s) {
            sum = prefix_sum[n] - prefix_sum[s - 1] + prefix_sum[e];
        }
        else {
            sum = prefix_sum[e] - prefix_sum[s - 1];
        }
        if (sum < k) {
            answer++;
        }
        if (n == m) {
            break;
        }
    }
    return answer;
}

int main()
{
    int T;
    cin >> T;
    while (T--) {
        int n, m, k;
        int prefix_sum[MAX] = { 0 }; 
        cin >> n >> m >> k;
        for (int i = 1, c; i <= n; i++) {
            cin >> c;
            prefix_sum[i] = prefix_sum[i - 1] + c;
        }
        cout << solution(n, m, k, prefix_sum) << '\n';
    }
    return 0;
}
