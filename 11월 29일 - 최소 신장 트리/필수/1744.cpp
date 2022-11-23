#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/*
 * <1774번 수 묶기>
 *
 * 1) 벡터로 입력받아 정렬하기
 *   i) 입력받은 벡터의 크기가 1일 경우, 그냥 그 수 그대로 출력할 것
 *
 * 2) 계산 시 주의사항
 *   i) 곱하기는 음수는 음수끼리, 양수는 양수끼리
 *   ii) 곱할 때는 절댓값이 큰 것끼리 (ex. 2,3,4,5 => 5*4+3*2 > 5*3+4*2)
 *   iii) 0이 존재하고, 전부 곱하고 나서 음수가 남아있으면 0과 음수를 곱함
 *   iv) 0이 존재하나, 전부 곱하고 나서 음수가 없으면, 0은 그냥 더함 (다른 수와 곱하지 않을 것)
 *   v) 1은 다른 수와 곱하지 않고 그냥 더할 것

 */

int solution(vector<int> &minus, vector<int> &plus, bool zero) {
    int sum = 0;

    if (minus.size()) { // 음수 계산
        sort(minus.begin(), minus.end());

        for (int i = 0; i < minus.size(); i += 2) {
            if (i == minus.size() - 1) { // 현재 인덱스가 마지막일 때
                if (!zero) { // 0이 없으면 음수를 더해야 함 (아니면 0이랑 곱해서 0을 더함)
                    sum += minus[i];
                }
            } else {
                sum += minus[i] * minus[i + 1];
            }
        }
    }

    if (plus.size()) { // 양수 계산
        sort(plus.begin(), plus.end(), greater<>());

        for (int i = 0; i < plus.size(); i += 2) {
            if (i == plus.size() - 1) { // 현재 인덱스가 마지막일 때
                sum += plus[i];
            } else if (plus[i] == 1 || plus[i + 1] == 1) { // 1은 그냥 더하는 것이 좋다
                sum += plus[i] + plus[i + 1];
            } else {
                sum += plus[i] * plus[i + 1];
            }
        }
    }

    return sum;
}

int main() {
    int n, tmp;
    cin >> n;
    if (n == 1) {
        cin >> tmp;
        cout << tmp;
        return 0;
    }

    vector<int> minus;
    vector<int> plus;
    bool zero = false;

    for (int i = 0; i < n; i++) {
        cin >> tmp;
        if (tmp < 0) {
            minus.push_back(tmp);
        } else if (tmp > 0) {
            plus.push_back(tmp);
        } else {
            zero = true;
        }
    }

    cout << solution(minus, plus, zero);
}