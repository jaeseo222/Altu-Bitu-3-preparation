#include <iostream>
#include <vector>
using namespace std;
vector<bool> visited(10, false);
vector<int> order(10, false); //주자 순서
/**
 * [힌트] 입력이 그렇게 크지 않네요! 모든 경우의 수를 다 해보면 될 것 같아요.
 *        3아웃이 되면 아웃 카운트와 출루한 주자들이 모두 리셋되고 새로운 이닝이 시작된다는 규칙을 잘 기억해주세요!
 */

/* 출루한 주자들의 상태 업데이트 */
int hit(vector<bool> &state, int n) {
    int score = 0;
    for (int i = 3; i > 0; i--) {
        if (!state[i]) {
            continue;
        }
        state[i] = false; //주자 위치 이동
        if (i + n >= 4) { //홈으로 들어오는 경우
            score++;
        }
        else {
            state[i + n] = true;
        }
    }
    //현재 타자의 위치 설정하기
    if (n == 4) { //타자가 홈런을 날렸을 경우
        return score + 1;
    }
    //안타를 쳤을 경우
    state[n] = true;
    return score;
}
/* 타순이 결정됐을 때 경기에서 얻는 점수 구하기 */
int getScore(vector<vector<int>> &inning, int n) {
    int score = 0, i = 1;
    vector<bool> state(4, false);
    for (int cur = 0; cur<n; cur++)
    {
        state = vector<bool>(4, false); //출루한 주자 리셋
        int out = 0;
        while(out < 3) {
            int player = order[i]; //타석으로 나갈 주자
            i = i % 9 + 1;
            if (inning[cur][player] == 0) { //아웃
                out++;
                continue;
            }
            score += hit(state, inning[cur][player]);
        }
    }
    return score;
}
/* 타순 정하기 */
void game(int cnt, int &n, vector<vector<int>> &inning, int &max_score) {
    if (cnt == 4) { //4번째 타자는 1로 고정
        game(cnt + 1, n, inning, max_score);
        return;
    }
    if (cnt == 10) { //9명의 타자 순서 정해진 경우
        int score = getScore(inning, n);
        max_score = max(score, max_score);
        return;
    }
    for (int i = 2; i <= 9; i++) {
        if (visited[i]) {
            continue;
        }
        visited[i] = true;
        order[cnt] = i;
        game(cnt + 1, n, inning, max_score);
        visited[i] = false;
    }
}
int main() {
    int n; cin >> n; //이닝 횟수
    int score, max_score = 0;
    vector<vector<int>> inning(n, vector<int>(10)); //타자들이 각 이닝에서 얻는 결과
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= 9; j++) {
            cin >> inning[i][j];
        }
    }
    order[4] = 1; //1번 선수는 4번 타자로 고정
    visited[1] = true;

    game(1, n, inning, max_score);
    cout << max_score;
    return 0;
}