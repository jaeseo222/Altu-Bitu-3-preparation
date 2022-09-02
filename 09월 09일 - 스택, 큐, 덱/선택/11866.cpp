#include <iostream>
#include <queue>

using namespace std;
/*
 * 큐의 처음과 끝을 연결하여 원을 구현
 * 큐에 아무것도 남아있지 않을 때까지 N 번째 원소를 큐에서 제거
*/

void josephProb(int n, int k)
{
    queue<int> q;
    for (int i = 0; i < n; i++) { // 큐에 N개의 원소 넣기
        q.push(i + 1);
    }
    cout << "<";
    while (!q.empty()) {
        for (int i = 0; i < k - 1; i++) { // K 번째임에 주의
            q.push(q.front()); // 큐의 가장 앞에 있는 원소를 가장 뒤로 옮김
            q.pop();
        }
      cout << q.front();
        if (q.size() == 1) {  // 큐의 원소가 하나일 경우
            cout << ">";
            
        }
        else { // 큐의 원소가 여러 개일 경우
            cout << ", ";
        }
        q.pop(); // 큐에서 원소 제거
    }

}

int main()
{
    int n, k;
    // 입력
    cin >> n >> k;
    // 연산 & 출력
    josephProb(n, k);
}
