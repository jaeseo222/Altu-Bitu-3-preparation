#include <iostream>
#include <algorithm>
using namespace std;

int n;
typedef struct 
{
    int guess_num, strike, ball;
} Data;
Data questions[110];

bool check(int t){
    string a = to_string(t);
    if(a[0] == a[1] || a[1] == a[2] || a[0] == a[2]) return false;
    for(int qst = 0; qst < n; qst++){
        int strike = 0, ball = 0;
        string tmp = to_string(questions[qst].guess_num);
        for(int i = 0 ; i < 3; i++){
            if(a[i] - '0' == 0) return false;
            for(int j = 0; j < 3; j++){
                if(i == j && a[i] == tmp[j]) strike++;
                else if(a[i] == tmp[j]) ball++;
            }
        }
        //cout<<arr[0]<<arr[1]<<arr[2]<<" "<<tmp<<" "<<" "<<strike<<" "<<ball<<'\n';
        if(questions[qst].strike != strike ||questions[qst].ball != ball) return false;
    }
   // cout<<'\n';
   
    return true;
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    int answer = 0;

    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        questions[i] = {a, b, c};
    }

    for(int i = 111; i <= 999; i++){
            if(check(i)) answer++;
    }
    cout<<answer;
  
    return 0;
}
