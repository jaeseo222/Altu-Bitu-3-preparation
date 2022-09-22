#include<iostream>
#include<queue>

using namespace std;

int main(){
    //입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,x;
    priority_queue<int, vector<int>, greater<int>> pq; //최소 힙 구현(오름차순)

    //입력
    cin >> n;
    while(n--){
        cin >> x;

        if(x){ //x가 자연수인 경우
            pq.push(x);
            continue;
        }

        //x가 0인 경우
        if(!pq.empty()){
            cout<<pq.top()<<'\n';
            pq.pop();
        }
        else{ //배열이 비어있으면 0 출력
            cout <<0<<'\n';
        }
    }
    return 0;

}