#include <iostream>
using namespace std;

/*
    Java :  첫 단어는 소문자로 쓰고, 다음 단어부터는 첫 문자만 대문자로 쓴다. 또, 모든 단어는 붙여쓴다.
        ex) javaIdentifier, longAndMnemonicIdentifier, name, bAEKJOON

    C++ : 소문자만 사용한다. 단어와 단어를 구분하기 위해서 밑줄('_')을 이용한다.
        ex) c_identifier, long_and_mnemonic_identifier, name, b_a_e_k_j_o_o_n
*/

/**
 * 1. 입력으로 주어진 변수가 C++ 형식에도 맞고, JAVA 형식에도 맞을 수 있음 (ex. name)
 * 2. "Error!"인 경우 (C++)
 *    2-1. 언더바('_')로 시작하거나, 끝나는 변수
 *    2-2. 언더바('_')가 연속해서 등장하는 변수
 *    2-3. 대문자가 등장하는 변수
 * 3. "Error!"인 경우 (Java)
 *    3-1. 대문자로 시작하는 변수
 *    3-2. 언더바('_')가 등장하는 변수
 */

bool isCpp(string str) { // c++ 형식인가?
    for (int i = 0; i < str.size(); i++) {
        if (isupper(str[i])) //대문자가 있으면 안됨
            return false;
        if (str[i] == '_' &&
            (i == 0 || i == str.size() - 1 || str[i - 1] == '_')) //첫 or 마지막 글자가 '_' 또는 '_'가 연속 등장
            return false;
    }
    return true;
}

bool isJava(string str) {                                     // java 형식인가?
    return !isupper(str[0]) && str.find('_') == string::npos; //첫 글자가 대문자거나, '_'가 있으면 안됨
}

string changeToCpp(string &str) {
    string result = "";

    for (int i = 0; i < str.length(); i++) {
        if (isupper(str[i])) { // 대문자라면 앞에 _ 삽입
            result += '_';
        }
        result += tolower(str[i]); //소문자로 추가
    }

    return result;
}

string changeToJava(string &str) {
    string result = "";

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '_') {
            result += toupper(str[i + 1]); // _ 다음 문자를 대문자로 바꿈
            i++;
        } else {
            result += str[i];
        }
    }

    return result;
}

int main() {
    string str;
    cin >> str;

    bool is_cpp = isCpp(str);
    bool is_java = isJava(str);

    if (is_cpp && is_java) { //두 형식에 모두 부합하면 그냥 출력
        cout << str;
    } else if (is_cpp) { // c++ 형식이라면 java로 바꿔서 출력
        cout << changeToJava(str);
    } else if (is_java) { // java 형식이라면 c++로 바꿔서 출력
        cout << changeToCpp(str);
    } else //둘 다 아니라면 에러
        cout << "Error!";
}
