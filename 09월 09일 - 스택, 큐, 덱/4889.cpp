#include<iostream>
#include<stack>
#include<string>
using namespace std;

int changeLetter(string s){ //괄호를 바꾸는 최소 연산의 수를 구하는 함수
    int count = 0; //최소 연산의 수
    stack<char> st;

    //'{}' 쌍은 제외하고 문자열을 스택에 저장
    for (int i = 0; i < (int) s.length(); i++) {
        if (s[i] == '}' && !st.empty() && st.top() == '{') {
            st.pop();
        } else {
            st.push(s[i]);
        }
    }

    //스택이 빌 때 까지 연산 횟수 계산
    while (!st.empty()) {
        //스택의 맨 위 문자 2개
        char a = st.top(); st.pop();
        char b = st.top(); st.pop();

        if (a == b) { count++; } //'{{' or '}}'이면 괄호흫 1번만 바꾼다
        else { count += 2; } //'}{' 이면 2번 바꾼다
    }

    return count;
}

int main(){
    string s; //문자열 입력받을 변수
    int num = 0; //테스트 케이스 번호

    while(1) {
        //입력
        cin >> s;

        if (s[0] == '-') { //종료조건: '-'가 입력되면 종료
            break;
        }

        int ans = changeLetter(s); //연산 횟수 계산

        //출력
        num++;
        cout << num << ". " << ans << '\n';
    }

    return 0;
}
