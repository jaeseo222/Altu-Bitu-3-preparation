#include <iostream>
#include <vector>
#include <algorithm>    //reverse()
using namespace std;

const int MAX_ALPHA=26; //알파벳 대문자 종류 개수

/**
 * [힌트] 앞뒤로 반복되어 나올 알파벳과 가운데에 위치할 알파벳을 분리한다면 
 *        펠린드롬을 쉽게 구현할 수 있지 않을까요?
 * 
 * 1. 문자열 입력받기
 * 2. 문자열에서 사용된 알파벳의 개수를 대문자별로 저장하기
 *    (아스키코드를 통해 문자를 숫자로 바꿔 배열의 인덱스와 매치해 쉽게 카운트 가능!)
 * 3. 알파벳 중 사용된 개수가 홀수이면 가운데(center)에 사용
 *    이때 홀수 개수의 알파벳이 2개 이상이면 -> 실패!
 * 4. 사용된 알파벳 개수/2만큼 str에 더하기
 * 5. (str -> center -> 뒤집혀진 str) 순으로 출력
 */

vector<int> countAlpha(string input) { //사용된 알파벳 개수 세기

    vector<int> alpha(MAX_ALPHA, 0);  //문자별 개수 저장할 vector

    for(int i=0; i<input.length(); i++) {
        //i번째 문자(input[i])가 'A'라면 아스키코드(혹은 유니코드)는 65
        //'A'의 개수를 0번째 인덱스에, 'Z'의 개수를 25번째 인덱스에 저장
        alpha[input[i]-'A']++;
    }

    return alpha;
}

string makePalindrome(string input) { //펠린드롬 생성 함수
    
    vector<int> alpha=countAlpha(input);
    string center="", str="", ans;   //center: 가운데에 위치할 문자 저장, str: 앞뒤로 사용할 문자열
    
    for(int i=0; i<MAX_ALPHA; i++) { //'A'부터 'Z'까지 사용된 알파벳 개수 파악

        if(alpha[i]%2) { //해당 알파벳 개수가 홀수라면
            if(center.length()) {
                //center에 저장된 문자가 1개 이상이라면 (즉 홀수인 알파벳이 2개 이상이라면)
                return "I'm Sorry Hansoo";
            }

            //center에 저장된 문자가 아직 존재하지 않는다면 center에 저장
            center=(char)(i+'A');
        } 

        for(int j=0; j<alpha[i]/2; j++) {
            //(사용된 알파벳의 개수/2)만큼 str에 추가
            //'A'부터 'Z' 순으로 for문을 통과하므로 알파벳 순으로 str 저장
            str+=(char)(i+'A');
        }
    }

    ans=str+center;
    reverse(str.begin(), str.end());
    ans+=str;
    
    return ans;
}

int main() {
    string input, ans;   //입력받은 문자열 저장
    cin>>input;

    ans=makePalindrome(input);
    cout<<ans;
    return 0;
}