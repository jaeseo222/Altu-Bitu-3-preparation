#include<iostream>
#include<vector>
#include<queue>
typedef long long ll;
using namespace std;

/* 감소하는 수의 최대값은 9876543210(10자리) -> long long타입
 * queue 이용:
 * 2, 21, 20, 210,... 와 같이 1의자리 보다 작은 숫자를 더하며 '감소하는 수'를 계속 큐에 push*/

vector<ll> decreaseNum(){ //감소하는 수들을 벡터에 저장하는 함수
    queue<ll> q;
    vector<ll> v; //감소하는 수 저장할 벡터

    for (int i = 0; i <= 9; i++) { //1자리 감소하는 수(0부터 9)
        q.push(i);
        v.push_back(i);
    }

    while (!q.empty()) {
        ll num1 = q.front();
        int last = num1 % 10; //num1의 1의 자리수
        q.pop();

        //1의자리 보다 작은 수 끝에 붙이고 큐에 push,벡터에 저장
        for (int i = 0; i < last; i++) {
            ll num2 = num1 * 10 + i;
            q.push(num2);
            v.push_back(num2);
        }
    }
    return v;
}

ll findNum(vector<ll> v, int n){ //벡터에서 n번째 감소하는 수 찾는 함수
    if(n >= v.size()){
        return -1;
    }
    return v[n];
}

int main(){
    //입력
    int N;
    cin>>N;

    //연산, 출력
    vector<ll> v = decreaseNum();
    cout << findNum(v, N)<<'\n';

    return 0;
}