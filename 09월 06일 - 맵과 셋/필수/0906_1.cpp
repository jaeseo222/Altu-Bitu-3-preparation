/******************************************************************************

                              필수문제 11723 집합 __vector 사용 버전
                              1조 서동은 8.30
*******************************************************************************/

#include <iostream>
#include <vector>
using namespace std;
const int SIZE=21;

int main(){
ios::sync_with_stdio(0); cin.tie(0);
//입력
int n; cin>>n;
vector<bool> s(SIZE,false); // 0~20의 유무를 나타낼 배열을 false로 초기화

for(int i=0;i<n;i++){
    string command;
    cin>>command;

    if(command=="all") 
        s.assign(SIZE,true); //true의 값으로 SIZE개의 원소를 할당
    else if(command=="empty") 
        s.assign(SIZE,false);
    else{
        int x; cin>>x;
        if(command=="add") 
            s[x]=true;
        else if(command=="remove") 
            s[x]=false;
        else if(command=="check") 
            cout<<s[x]<<'\n'; // true이면 1을, false이면 0을 출력
        else if(command=="toggle")
            s[x]=!s[x]; // true이면 false를, false면 true를 대입
    }
}
}
/******************************************************************************

                    필수문제 11723 집합 __bit masking 사용 버전
                              1조 서동은 8.30
*******************************************************************************/

#include <iostream>
using namespace std;
int M;
int S, reset; // S의 20개의 비트가 1 부터 20까지 숫자의 유무(1 or 0)를 표현할 것입니다

void add(int n){
    if((S & (1 << n)) == 0) S |= (1 << n);
}
void Remove(int n){
    if(S & (1 << n)) S &= ~(1 << n);
}
void print_check(int n){
    if(S & (1 << n)) cout<<1<<'\n';
    else cout<<0<<'\n';
}
void toggle(int n){
    if(S & (1 << n)) Remove(n);
    else add(n);
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //입력
    cin>>M;
    //명령이 all일 때 reset할 수를 초기화해줍니다
    for(int i = 1; i <= 20; i++) reset |= (1 << i);
    
    while(M--){
        string s; cin>>s;
        if(s == "all") S = reset;
        else if(s == "empty") S = 0;
        else {
            int n; cin>>n;
            if(s == "add") add(n);
            else if(s == "remove") Remove(n);
            else if(s == "check") print_check(n); //출력
            else if(s == "toggle") toggle(n);
        }
    }
    return 0;
}
