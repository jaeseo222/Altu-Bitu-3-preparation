#include <iostream>
#include <vector>

using namespace std;

bool isGroup(string str) {
    char cur = NULL; //현재의 문자
    vector<bool> alphabet(26, false); // 단어에서 알파벳 문자의 출현 유무를 나타내는 bool형 배열을 선언

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == cur) { //연속해서 나타난 문자라면 
            continue;
        }
      
        if (alphabet[str[i] - 'a']) {  //이전의 문자와 다른 문자가 나타났다면
            return false;
        }
        cur = str[i];
        alphabet[str[i] - 'a'] = true;
    }
    return true;
}

/**
 * [그룹 단어 체커]
 * - 이미 등장한 알파벳을 배열의 인덱스(알파벳)를 활용해서  true/false로 저장
 * - 처음 등장하는 알파벳은 등장체크 업데이트 하고, 무리에서 떨어졌는데 이미 등장한 알파벳이면 그룹 단어가 아니다.
 * 입력받은 단어가 그룹단어인지 아닌지 판단하는 방법?
 * 1. 단어의 n번째 문자가 n-1번째 문자와 같지 않고(연속하지 않고),
 * 2. n번째 문자에 해당하는 배열 값이 true 라면(이미 나왔던 문자라면) 그룹단어가 아니다.
 */

int main() {
    int n, result = 0;

    //입력
    cin >> n;
    while (n--) {
        string word;
        cin >> word;

        //연산
        if (isGroup(word)) { //그룹 단어인지 확인
            result++;
        }
    }

    //출력
    cout << result;
    return 0;
}
