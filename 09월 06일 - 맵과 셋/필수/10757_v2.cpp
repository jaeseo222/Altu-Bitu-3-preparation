//스택 사용
#include <iostream>
#include <stack>
using namespace std;

/*
    매개변수에 &를 붙이면 원본을 참조하게 됩니다.
    **이 문제에서는 굳이 참조자를 사용할 필요는 없지만, C++에서는 주로 &를 붙입니다**
*/
stack<int> plusAB(string &a, string &b) {
    int idxA = a.size() - 1; // 일의 자리 인덱스
    int idxB = b.size() - 1;
    int carry = 0;
    stack<int> ans;

    while (idxA >= 0 && idxB >= 0) {
        int num = (a[idxA--] - '0') + (b[idxB--] - '0'); // 문자를 숫자로 바꾸어 더하기, 그리고 인덱스 변경

        num += carry;       // num에 carry 더해주기. (carry는 어차피 1 아니면 0)
        carry = num / 10;   // num의 값이 10이상이면 carry가 1, 아니면 0
        ans.push(num % 10); // 올림을 제외한 값만 스택에 push
    }

    // 1. a가 더 긴 경우
    while (idxA >= 0) {
        int num = a[idxA--] - '0';

        num += carry;
        carry = num / 10;
        ans.push(num % 10);
    }

    // 2. b가 더 긴 경우
    while (idxB >= 0) {
        int num = b[idxB--] - '0';

        num += carry;
        carry = num / 10;
        ans.push(num % 10);
    }

    // 3. a와 b의 길이가 같은데, carry가 발생했을 수도 있으니 체크하기
    if (carry)
        ans.push(1);

    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string a, b;
    cin >> a >> b;

    stack<int> ans;
    ans = plusAB(a, b);

    while (!ans.empty()) {
        cout << ans.top();
        ans.pop();
    }
}