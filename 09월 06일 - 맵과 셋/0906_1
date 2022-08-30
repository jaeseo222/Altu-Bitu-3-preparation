/******************************************************************************

                              필수문제 11723 집합 __vector 사용 버전
                              1조 서동은 8.30
*******************************************************************************/

#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int M;
int reset_arr[21];

void Add(int n){
    if(find(v.begin(),v.end(),n) == v.end()) v.push_back(n);
}
void Remove(int n){
    auto iter = find(v.begin(),v.end(),n);
    if(iter != v.end()) v.erase(iter); 
}
void print_check(int n){
    if(find(v.begin(),v.end(),n) == v.end()) cout<<0<<'\n';
    else cout<<1<<'\n';
}
void Toggle(int n){
    auto iter = find(v.begin(),v.end(),n); 
    if(iter == v.end()) v.push_back(n);
    else v.erase(iter);
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    int n; 
    //입력
    cin>>M;
    // reset_arr를 초기화
    for(int i = 1; i <= 20; i++) reset_arr[i-1] = i;
    while(M--){
        cin>>s;
        if(s == "all") v.assign(reset_arr, reset_arr+20);
        else if(s == "empty") v.clear();
        else {
             cin>>n;
            if(s == "add") Add(n);
            else if(s == "remove") Remove(n);
            else if(s == "check") print_check(n); //출력
            else if(s == "toggle") Toggle(n);
        }
    }
    return 0;
}
/******************************************************************************

                    필수문제 11723 집합 __bit masking 사용 버전
                              1조 서동은 8.30
*******************************************************************************/

#include <iostream>
using namespace std;
int M;
int S, reset; // S의 20개의 비트가 1 부터 20까지 숫자의 유무(1 or 0)를 표현할 것입니다

void Add(int n){
    if((S & (1 << n)) == 0) S |= (1 << n);
}
void Remove(int n){
    if(S & (1 << n)) S &= ~(1 << n);
}
void print_check(int n){
    if(S & (1 << n)) cout<<1<<'\n';
    else cout<<0<<'\n';
}
void Toggle(int n){
    if(S & (1 << n)) Remove(n);
    else Add(n);
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //입력
    cin>>M;
    //reset할 수를 초기화해줍니다
    for(int i = 1; i <= 20; i++) reset |= (1 << i);
    
    while(M--){
        string s; cin>>s;
        if(s == "all") S = reset;
        else if(s == "empty") S = 0;
        else {
            int n; cin>>n;
            if(s == "add") Add(n);
            else if(s == "remove") Remove(n);
            else if(s == "check") print_check(n); //출력
            else if(s == "toggle") Toggle(n);
        }
    }
    return 0;
}
