#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, int s, vector<int> cow) {
    int cnt = 0;
    int left = 0;
    int right = n - 1;

    while (left < right) {
        if (cow[left] + cow[right] > s) { //무게 합이 s 초과
            right--;
            continue;
        }

        cnt += right - left;
        left++;
    }
    return cnt;
}

int main() {
    //입력
    int n, s;
    cin >> n >> s;
    vector<int> cow(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> cow[i];
    }

    //연산, 출력
    sort(cow.begin(), cow.end()); //정렬
    cout << solution(n, s, cow);

    return 0;
}