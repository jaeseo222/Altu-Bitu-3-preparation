#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 * [N번째 큰 수]
 * 
 * 메모리 제한이 있기 때문에, 입력값을 모두 저장해서 N번째 큰수를 계산하면 메모리 초과가 발생한다.
 * 최소 힙을 만들어서 상위 n개만 저장하여 heap[0]을 현재까지의 N번째 큰수로 유지하자!
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, input;
    priority_queue<int, vector<int>, greater<>> pq; //최소 힙, 비교함수 처리가 정렬이랑 반대

    cin >> n;
    int size = n * n;
    while (size--) {

        //입력
        cin >> input;

        //연산
        pq.push(input);
        if (pq.size() > n) { //최소 힙의 크기가 n 을 넘어가면 가장 작은 값 삭제
            pq.pop();
        }
    }

    //출력
    cout << pq.top();
    return 0;
}
