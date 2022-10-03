#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * 작은 값부터 측정 가능 여부를 확인하기 위해, 오름차순으로 정렬
 * 현재 0부터 sum까지 모든 무게를 빠짐없이 측정 가능하다고 했을 때, 새로운 무게는 sum+1보다 작거나 같아야 함.
 * ex) 현재 1~5 측정 가능한데, 다음 값이 7인 경우 -> 6은 측정 불가
 *
 * 만약 이 조건을 만족할 경우, 측정 가능한 범위는 [1, sum+새로운 무게]로 갱신됨.
 * 모든 저울을 살펴봤는데도 비어 있는 값이 없으면 sum+1 리턴
 */

int solution(vector<int> &weight) {
    int sum = 0;

    for (int i = 0; i < weight.size(); i++) {
        if (sum + 1 < weight[i]) {
            return sum + 1;
        }
        sum += weight[i];
    }
    return sum + 1;
}

int main() {
    int n;

    //입력
    cin >> n;

    vector<int> weight(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }
    sort(weight.begin(), weight.end()); //오름차순 정렬

    //연산, 출력
    cout << solution(weight);

    return 0;
}