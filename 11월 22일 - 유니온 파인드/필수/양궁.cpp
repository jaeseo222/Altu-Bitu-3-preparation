#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define MAX_SCORE 10 // 양궁 최대 점수
using namespace std;

vector<int> answer = {-1};
int maxDiff = 0;

/* 라이언이 answer보다 낮은 점수의 비중이 높은지 여부 반환*/
bool compare(vector<int> &ryan) {
    for(int i=MAX_SCORE-1; i>=0; i--) {
        if(answer[i] > ryan[i]) {
            return false;
        }
        if(answer[i] < ryan[i]) {
            return true;
        }
    }
}
/* 라이언과 어피치의 점수 차 반환 */
int getDiff(vector<int> &ryan, vector<int> &appeach) {
    int appeach_score = 0;
    int lion_score = 0;
    for(int i=0; i<MAX_SCORE; i++) {
        // 어피치와 라이언이 모두 0점을 쏠 경우 아무도 점수를 가져가지 않음
        if (appeach[i] == 0 && ryan[i] == 0) {
            continue;
        }
        // 어피치가 라이언보다 같거나 더 많이 쏜 경우: 어피치 득점
        if (appeach[i] >= ryan[i]) {
            appeach_score += MAX_SCORE - i;
        }
        // 라이언이 어피치보다 더 많이 쏜 경우: 어피치 득점 
        else {
            lion_score += MAX_SCORE - i;
        }
    }
    return lion_score - appeach_score;
}
/* answer, maxDiff 엄데이트 */
void update(int diff, vector<int> &ryan) {
    // 1. 현재 점수 차가 가장 큰 경우: maxDiff 업데이트
    if (diff > maxDiff) {
        maxDiff = diff;
        answer = ryan;
    }
    // 2. 현재 점수 차가 maxDiff과 같은 경우: 낮은 점수의 비중이 더 크면 maxDiff 업데이트
    else if (diff == maxDiff && compare(ryan)){
        answer = ryan;
    }
}

void combination(int cnt, int not_used, vector<int> &ryan, vector<int> &appeach) {
    if (not_used == 0 || cnt == MAX_SCORE + 1) {
        ryan[MAX_SCORE] = not_used; // 남은 화살은 0점 개수로 포함
        int diff = getDiff(ryan, appeach);
        if(diff > 0) {
            update(diff, ryan);
        }
        ryan[MAX_SCORE] = 0; // 0점 개수 원래대로 초기화
        return;
    }
    // cnt번째 점수를 가져가는 경우 (appeach[cnt]+1만큼 쏘는 경우)
    if (not_used > appeach[cnt]) { 
        ryan[cnt] = appeach[cnt] + 1;
        combination(cnt + 1, not_used - ryan[cnt], ryan, appeach);
        ryan[cnt] = 0;
    }
    // cnt번째 점수를 가져가지 않는 경우 (0점을 쏘는 경우)
    combination(cnt + 1, not_used, ryan, appeach);
}

vector<int> solution(int n, vector<int> info) {
    vector<int> order(MAX_SCORE + 1, 0);
    combination(0, n, order, info);
    return answer;
}

/**
 * 우리의 목표는 라이언이 최대 점수차로 어피치를 이기는 것! 어피치가 6점 과녁에 2발 쐈을 때 라이언이 1발을 맞히면 의미 없음
 *  => 점수를 얻는 경우: 라이언이 어피치보다 1발을 더 맞히는 경우
 *     점수를 얻지 못하는 경우: 0발을 쏘는 경우
 * 
 * 1. 라이언이 점수를 얻는 경우의 수를 백트래킹으로 탐색
 *    (완전탐색으로 경우의 수를 구할 경우 시간초과 발생하므로 위 조건에 따라 탐색)
 * 
 * 2. 남은 화살이 0이 되거나 탐색하고 있는 과녁이 마지막 과녁(0점)인 경우 점수 차 계산
 *    - 둘 다 0점인 경우: 아무도 점수를 얻지 않음
 *    - 어피치가 라이언보다 많거나 동일하게 맞힌 경우: 어피치 득점
 *    - 라이언이 어피치보다 많이 맞힌 경우: 라이언 득점
 * 
 * 3. 얻은 점수차가 0점보다 큰 경우 -> 최대점수차(maxDiff) 업데이트할지 확인
 *    - 현재 점수차 > 최대 점수차: maxDiff와 answer 업데이트
 *    - 현재 점수차 == 최대 점수차: 현재 answer보다 낮은 점수의 배점이 큰 경우에만 업데이트
 */
int main() {
    int n = 5; vector<int> info = {2, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0};
    // int n = 1; vector<int> info = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    // int n = 9; vector<int> info = {0, 0, 1, 2, 0, 1, 1, 1, 1, 1, 1};
    // int n = 10; vector<int> info = {0, 0, 0, 0, 0, 0, 0, 0, 3, 4, 3};
    vector<int> result = solution(n, info);
    for (int i = 0; i <= MAX_SCORE; i++) {
        cout << result[i] << " ";
    }
    return 0;
}