#include<iostream>
#include<stack>
#include<string>

using namespace std;

stack<char> removePair(string s) { //짝이 맞는 괄호쌍들을({}) 제거하는 함수
    //'{}' 쌍은 제외하고 문자열을 스택에 저장
    stack<char> st;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '}' && !st.empty() && st.top() == '{') {
            st.pop();
        } else {
            st.push(s[i]);
        }
    }

    return st;
}

int countChange(stack<char> st) { //괄호를 바꾸는 최소 연산의 수를 구하는 함수
    int count = 0; //최소 연산의 수

    //스택이 빌 때 까지 연산 횟수 계산
    while (!st.empty()) {
        //스택의 맨 위 문자 2개
        char a = st.top();
        st.pop();
        char b = st.top();
        st.pop();

        if (a == b) { //'{{' or '}}'이면 괄호를 1번만 바꾼다
            count++;
        }
        else { //'}{' 이면 2번 바꾼다
            count += 2;
        }
    }

    return count;
}

int main() {
    string s; //문자열 입력받을 변수
    int num = 0; //테스트 케이스 번호

    while (cin >> s) { //입력
        if (s[0] == '-') { //종료조건: '-'가 입력되면 종료
            break;
        }

        //연산
        stack<char> st = removePair(s);
        int ans = countChange(st);

        //출력
        cout << ++num << ". " << ans << '\n';

    }

    return 0;
}
