//스택 사용
#include <iostream>
#include <stack>
using namespace std;

/*
    매개변수에 &를 붙이면 원본을 참조하게 됩니다.
    **이 문제에서는 굳이 참조자를 사용할 필요는 없지만, C++에서는 주로 &를 붙입니다**
*/
stack<int> calcPlus(string &a, string &b) {
    int idx_a = a.size() - 1; // 일의 자리 인덱스
    int idx_b = b.size() - 1;
    bool carry = false;
    stack<int> ans;

    while (idx_a >= 0 && idx_b >= 0) {
        int num = (a[idx_a--] - '0') + (b[idx_b--] - '0'); // 문자를 숫자로 바꾸어 더하기, 그리고 인덱스 변경

        num += carry;       // num에 carry 더해주기. (carry는 어차피 1 아니면 0)
        carry = num / 10;   // num의 값이 10이상이면 carry가 1, 아니면 0
        ans.push(num % 10); // 올림을 제외한 값만 스택에 push
    }

    // a에서 남은 숫자 반영
    while (idx_a >= 0) {
        int num = a[idx_a--] - '0';

        num += carry;
        carry = num / 10;
        ans.push(num % 10);
    }

    // 남은 올림 확인
    if (carry)
        ans.push(1);

    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string a, b;
    stack<int> ans;

    //입력
    cin >> a >> b;

    //연산
    if (a.length() < b.length()) // b의 길이가 더 길다면
        swap(a, b);

    ans = calcPlus(a, b);

    //출력
    while (!ans.empty()) {
        cout << ans.top();
        ans.pop();
    }
}