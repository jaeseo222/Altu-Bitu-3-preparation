#include <iostream>
#include <stack>
#include <vector>

using namespace std;

string stackToString(stack<char>& left, stack<char>& right) {
    // 두 개의 스택을 하나의 문자열로 합치는 함수

    string password;
    // 왼쪽 스택의 top 부터 하나씩 오른쪽 스택에 삽입
    while (!left.empty()) {
        right.push(left.top());
        left.pop();
    }
    // 현재 오른쪽 스택의 top에는 password의 앞글자부터 저장된 상태
    while (!right.empty()) {
        password += right.top();
        right.pop();
    }
	return password;
}

string findPassword(string log) {
    stack<char> left;   //커서 이전 내용을 저장
    stack<char> right;  //커서 이후 내용을 저장

    for (int i = 0; i < log.length(); i++) {
        switch (log[i]) {
        case '-':  //현재 커서 앞에 있는 글자 삭제
            if (!left.empty()) {
                left.pop();
            }
            break;
        case '<':  //커서를 왼쪽으로 이동
            if (!left.empty()) {
                right.push(left.top());
                left.pop();
            }
            break;
        case '>':  //커서를 오른쪽으로 이동
            if (!right.empty()) {
                left.push(right.top());
                right.pop();
            }
            break;
        default:  //문자인 경우, 입력을 하면 커서보다 왼쪽에 위치하므로 left에 삽입
            left.push(log[i]);
        }
    }

    string password = stackToString(left, right);
    return password;
}

/**
 * [키로거]
 *
 * 해당 풀이는, 글자 삽입 삭제 시 이동시키는 과정에서 생기는 코너케이스를 해결하기 위해 커서를 기준으로 왼쪽, 오른쪽으로 나눠서 값을 저장함
 *
 * 1. 커서 앞의 글자를 지울 때, 글자가 없는 경우 주의
 * 2. 커서를 왼쪽으로 이동할 때, 이미 가장 왼쪽에 커서가 있는 경우 주의
 * 3. 커서를 오른쪽으로 이동할 때, 이미 가장 오른쪽에 커서가 있는 경우 주의
 */

int main() {
    int tc;
    //입력
    cin >> tc;

    // 출력
    while(tc--) {
        string s;
        cin >> s;
        cout << findPassword(s) << '\n';
    }
    return 0;
}
