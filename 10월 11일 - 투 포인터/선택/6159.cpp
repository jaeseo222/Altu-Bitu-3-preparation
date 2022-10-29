#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 서로 다른 2개씩 짝 짓는 경우이므로 양 끝 포인터에서 시작 (오름차순 정렬을 미리 해줌)
 * 무게 합이 S 초과라면 더 작은 쪽으로 이동하기 위해 right 포인터 감소
 * 무게 합이 S 이하라면 left ~ right 사이에 있는 값과 현재 left와 짝 지었을 때도 S보다 작다는 것이므로 카운트 추가
 */

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