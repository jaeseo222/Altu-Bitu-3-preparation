#include<iostream>
#include<algorithm>
#include<string>
using namespace std;


/*
[가장 큰 수]
-입력 받은 각 수를 가장 큰 순서대로 정렬

[30의 배수]
-3의 배수 : 각 자리의 수의 합이 3의 배수
-10의 배수 : 일의 자리가 0
*/

//모든 자릿수 합이 3의 배수인지 확인하는 함수
bool checkThree(string n) {
    int sum = 0;
    for (int i = 0; i < n.size(); i++) {
        sum += n[i];
    }

    //더한 자릿수의 합이 3의 배수이면 n도 3의 배수
    if (sum % 3 == 0) {
        return true;
    }
    return false;
}

//n으로 만들 수 있는 30의 배수 중 가장 큰 수를 구하는 함수
string findNum(string n) {
    sort(n.begin(), n.end(), greater<>()); //각 자릿수 내림차순 정렬

    //30의 배수이면 숫자 리턴
    if (n[n.size() - 1] == '0' && checkThree(n)) {
        return n;
    }
    return "-1";

}

int main() {
    string n;
    cin >> n;
    
    //N이 최대 10^5개의 숫자로 구성되어 있으므로 string타입 사용
    string ans = findNum(n);

    cout<<ans;
    return 0;

}
