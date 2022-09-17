#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, char> ci;

/*
    - 배열을 ?로 초기화 해주고, 입력대로 처리한다
    - 문제의 경우, 화살표를 고정시키고 바퀴를 돌리는데,
    - 풀 때에는 바퀴를 고정시키고, 화살표를 이동시키는 방식으로 풀었다. (출력시 방향을 바꿔야함)
    <주의 사항>
    1. ?이 아닌 문자가 저장되어있는데, 다른 문자를 저장하려는 경우
    2. 룰렛에 중복되는 문자가 있는 경우
*/

string makeResult(int index, int n, vector<char> &wheel) {
    string ans = "";

    for (int i = n; i > 0; i--) {
        ans += wheel[(i + index) % n];
    }

    return ans;
}

string makeWheel(int n, vector<ci> &record) {
    vector<char> wheel(n, '?');           //?로 초기화
    vector<bool> is_available(26, false); //알파벳 중복 체크

    int index = 0; //화살표가 가리키는 인덱스

    for (int i = 0; i < record.size(); i++) {
        int rot = record[i].first;
        int ch = record[i].second;

        index = (index + rot) % n; //화살표 이동

        if (wheel[index] == ch) {
            continue;
        }

        // 주의사항 체크
        // 다른 문자가 저장되어있거나, 이미 다른 곳에 문자가 사용된 경우
        if (wheel[index] != '?' || is_available[ch - 'A']) {
            return "!";
        }

        wheel[index] = ch;
        is_available[ch - 'A'] = true; // 2번 조건을 체크하기 위함
    }

    return makeResult(index, n, wheel);
}

int main() {
    //입력
    int n, k;
    cin >> n >> k;

    vector<ci> record(k, {0, 0}); //바퀴 회전 기록
    for (int i = 0; i < k; i++) {
        cin >> record[i].first >> record[i].second;
    }

    //출력
    cout << makeWheel(n, record);
}