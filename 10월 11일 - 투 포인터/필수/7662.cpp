#include <iostream>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;   //int 사용시 입력값으로 INT_MIN 들어올 경우, - (마이너스) 연산 시 INT 범위를 벗어나므로 에러 발생

/*
 * [힌트] 최솟값이라고 최소힙을 쓰라는 보장은 없죠.
 *        대신 최댓값과 최솟값을 따로 관리해주려면 해당 원소가 몇 개가 남았는지도 알아둬야겠어요!
 */
void popDummies(priority_queue<ll> &heap, map<ll, ll> &remained, int x) {
    while(!heap.empty() && remained[heap.top() * x]==0) {
        heap.pop();
    }
}
int main() {
    int t; cin>>t;  //테스트 케이스
    while(t--) {
        priority_queue<ll> max_queue, min_queue; //max_queue: 최대값 pop, min_queue: 최솟값 pop
        map<ll, ll> remained; //큐에 남아있는 원소의 개수 저장

        int k; cin>>k;  //입력 개수
        while(k--) {
            char op; //연산자
            ll x;    //피연산자
            cin>>op>>x;

            switch(op) {
                case 'I':
                    max_queue.push(x);
                    min_queue.push(-x); //최솟값 찾을 수 있도록 부호를 바꾸어 저장
                    remained[x]++;  //원소 개수 1 증가
                    break;

                case 'D':
                    if(x==-1) {
                        //이미 삭제된 값은 pop 하기
                        popDummies(min_queue, remained, x);
                        //최솟값 pop
                        if(!min_queue.empty()) {
                            remained[-min_queue.top()]--;
                            min_queue.pop();
                        }
                    } else {
                        //이미 삭제된 값은 pop 하기
                        popDummies(max_queue, remained, x);
                        //최댓값 pop
                        if(!max_queue.empty()) {
                            remained[max_queue.top()]--;
                            max_queue.pop();
                        }
                    }
            }
        }
        //이미 삭제된 값은 pop 하기
        popDummies(min_queue, remained, -1);
        popDummies(max_queue, remained, 1);
        
        if(max_queue.empty()) {
            cout<<"EMPTY\n";
        } else {
            cout<<max_queue.top()<<" "<<-min_queue.top()<<"\n";
        }
    }

    return 0;
}