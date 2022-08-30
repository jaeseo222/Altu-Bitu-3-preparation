#include <iostream>
#include <vector>
#include <algorithm>    // reverse()
using namespace std;
int main() {
    string a, b;    // 입력받는 두 수 A, B에 문자열로 저장
    cin>>a>>b;

    int i, j, p, q, num, carry=0;
    vector<int> ans;    // 연산 후 값 저장
    
    i=a.length();  // 연산에 사용할 A의 자리수
    j=b.length();  // 연산에 사용할 B의 자리수

    while(i>0 && j>0) {
        p=a[--i]-'0'; q=b[--j]-'0';
        num=(p+q+carry)%10;
        carry=(p+q+carry)/10;   // 한자리수 덧셈 후 나오는 십의 자리수
        ans.push_back(num);
    }
    while(i>0) {    // A에 수가 남아있을 경우
        p=a[--i]-'0';
        num=(p+carry)%10;
        carry=(p+carry)/10;
        ans.push_back(num);
    }
    while(j>0) {    // B에 수가 남아있을 경우
        q=b[--j]-'0';
        num=(q+carry)%10;
        carry=(q+carry)/10;
        ans.push_back(num);
    }
    if(carry) ans.push_back(carry); // 남은 수가 0이 아닐 경우

    reverse(ans.begin(), ans.end()); // 뒷자리수부터 덧셈 수행했으므로 vector 뒤집기

    for(int i=0; i<ans.size(); i++) cout<<ans[i];
    return 0;
}