#include <iostream>
#include <queue>
#include <map>
using namespace std;
/*
 * [힌트] 최대 힙과 최소 힙이 둘 다 필요할 것 같아요. 근데 한쪽에서 삭제된 데이터를 다른쪽에 반영하려면 어떻게 해야할까요? 
 *        '어떤' 데이터가 삭제됐는지 저장할 방법은 없을까요? 
 */
void popMin(priority_queue<int, vector<int>, greater<int>> &min_queue, map<int, int> &remained) {
    while(!min_queue.empty() && remained[min_queue.top()]==0) {
        min_queue.pop();
    }
}
void popMax(priority_queue<int> &max_queue, map<int, int> &remained) {
    while(!max_queue.empty() && remained[max_queue.top()]==0) {
        max_queue.pop();
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin>>t;  //테스트 케이스
    while(t--) {
        priority_queue<int> max_queue; //max_queue: 최대값 pop, min_queue: 최솟값 pop
        priority_queue<int, vector<int>, greater<int>> min_queue;
        map<int, int> remained; //큐에 남아있는 원소의 개수 저장

        int k; cin>>k;  //입력 개수
        while(k--) {
            char op; //연산자
            int x;    //피연산자
            cin>>op>>x;

            switch(op) {
                case 'I':
                    max_queue.push(x);
                    min_queue.push(x); //최솟값 찾을 수 있도록 부호를 바꾸어 저장
                    remained[x]++;  //원소 개수 1 증가
                    break;

                case 'D':
                    if(x==-1) {
                        //이미 삭제된 값은 pop 하기
                        popMin(min_queue, remained);
                        //최솟값 pop
                        if(!min_queue.empty()) {
                            remained[min_queue.top()]--;
                            min_queue.pop();
                        }
                    } else {
                        //이미 삭제된 값은 pop 하기
                        popMax(max_queue, remained);
                        //최댓값 pop
                        if(!max_queue.empty()) {
                            remained[max_queue.top()]--;
                            max_queue.pop();
                        }
                    }
            }
        }
        //이미 삭제된 값은 pop 하기
        popMin(min_queue, remained);
        popMax(max_queue, remained);
        if(max_queue.empty()) {
            cout<<"EMPTY\n";
        } else {
            cout<<max_queue.top()<<" "<<min_queue.top()<<"\n";
        }
    }

    return 0;
}