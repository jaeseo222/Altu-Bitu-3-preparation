#include <cctype> //isupper(), islower(), toupper(), tolower()
#include <iostream>
using namespace std;

/*
    Java :  첫 단어는 소문자로 쓰고, 다음 단어부터는 첫 문자만 대문자로 쓴다. 또, 모든 단어는 붙여쓴다.
        ex) javaIdentifier, longAndMnemonicIdentifier, name, bAEKJOON

    C++ : 소문자만 사용한다. 단어와 단어를 구분하기 위해서 밑줄('_')을 이용한다.
        ex) c_identifier, long_and_mnemonic_identifier, name, b_a_e_k_j_o_o_n


    ** 예외처리가 많은 문제 **
    <에러인 경우>
    1) 첫 글자가 소문자가 아닌 경우 (대문자나 _로 시작하는 경우)
    2) 마지막 문자가 _인 경우
    3) 대문자와 _가 같이 나오는 경우
    4) _가 연속으로 나오는 경우

    <고려사항>
    ** 변수명이 소문자로 이루어진 "한단어"인 경우, java, c++ 모두 해당되므로 그대로 출력
*/

bool capital = false, underbar = false;

bool isError(string &str) {
    // 1번 조건 체크 - 첫 글자가 소문자가 아닌 경우
    if (!islower(str[0])) {
        return true;
    }

    // 2번 조건 체크 - 마지막 문자가 _인 경우
    if (str[str.length() - 1] == '_') {
        return true;
    }

    // 3번 조건 체크 - 대문자와 _가 같이 나오는 경우
    // 4번 조건 체크 - _가 연속으로 나오는 경우
    for (int i = 1; i < str.length(); i++) { // 1번 조건을 체크해뒀기 때문에 1부터 시작해도 된다.
        if (isupper(str[i])) {
            capital = true;
        }
        if (str[i] == '_') {
            underbar = true;
            if (str[i - 1] == '_') { // 4번 조건
                return true;
            }
        }
    }
    if (capital && underbar) { // 3번 조건
        return true;
    }

    return false;
}

string changeToCPP(string &str) {
    string result = "";

    for (int i = 0; i < str.length(); i++) {
        if (islower(str[i])) {
            result += str[i];
        } else {
            result += '_';
            result += tolower(str[i]);
        }
    }

    return result;
}

string changeToJava(string &str) {
    string result = "";
    bool checkUnderbar = false;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '_') {
            checkUnderbar = true;
        } else if (checkUnderbar) { //대문자로 바꾸어 넣기
            result += toupper(str[i]);
            checkUnderbar = false;
        } else {
            result += str[i];
        }
    }

    return result;
}

int main() {
    string str;
    cin >> str;

    if (isError(str)) {
        cout << "Error!\n";
    } else if (capital) { //입력받은 문자열이 Java
        cout << changeToCPP(str) << '\n';
    } else if (underbar) { //입력받은 문자열이 C++
        cout << changeToJava(str) << '\n';
    } else {
        //변수명이 소문자로 이루어진 "한단어"인 경우
        cout << str << '\n';
    }
}