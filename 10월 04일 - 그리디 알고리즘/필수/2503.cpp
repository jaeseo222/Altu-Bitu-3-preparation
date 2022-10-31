#include <iostream>
#include <algorithm>

using namespace std;

typedef struct {
    int num,
    strike,
    ball;
} Data;

bool checkStrikeBall(string s1, string s2, int strike, int ball) {
    int strike_cnt = 0, ball_cnt = 0;
    for (int i = 0; i < 3; i++) {
        if (s1[i] == s2[i]) { //위치+수 정확히 일치 -> 스트라이크
            strike_cnt++;
        }
        else if (s1.find(s2[i]) != s1.npos) { //위치 다른데 수가 존재 -> 볼
            ball_cnt++;
        }
    }
    if (strike != strike_cnt || ball != ball_cnt) {
        return false;
    }
    return true;
}

bool check(int n, int t, Data arr[]) {
    string s = to_string(t); // 숫자 t를 문자열 s로 바꿈
    if (s[0] == '0' || s[1] == '0' || s[2] == '0') { //0이 하나라도 있다면
        return false;
    }
    if (s[0] == s[1] || s[1] == s[2] || s[0] == s[2]) { // 서로 같은 수 하나라도 있다면
        return false;
    }
    for (int qst = 0; qst < n; qst ++) {
        string num = to_string(arr[qst].num);
        if (!checkStrikeBall(s, num, arr[qst].strike, arr[qst].ball)) {
            return false;
        }
    }
    return true;
}
/**
 * [숫자 야구]
 * 서로 다른 세 자리 수에서 위치 + 수 같으면 스트라이크, 위치는 다르고 수가 존재하면 볼
 * n개의 질문으로 수와 스트라이크와 볼 개수가 주어질 때, 이를 모두 만족하는 서로 다른 세 자리 정답 수의 개수
 *
 * [풀이]
 * 서로 다른 세 자리수는 123 ~ 987이 가능하다. 이는 총 865가지
 * 질문 n의 범위는 최대 100
 * 따라서 123부터 하나씩 증가시키며 정답이 되는지 검사해도 865 * 100 * 3(자릿수)으로 접근 충분히 가능!
 */
int main() {
    int n, answer = 0;
    cin >> n;
    Data arr[n];
    for (int i = 0; i < n; i ++) {
        cin >> arr[i].num >> arr[i].strike >> arr[i].ball;
    }
    for (int i = 123; i <= 987; i ++) {
        if (check(n, i, arr)) {
            answer ++;
        }
    }
    cout << answer;
    return 0;
}