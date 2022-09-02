#include <iostream>
#include <vector>
#include <queue>

using namespace std;
/*
 * 큐의 처음과 끝을 연결하여 원을 구현
 * 큐에 아무것도 남아있지 않을 때까지 N 번째 원소를 큐에서 제거
*/

vector<int> josephusProb(int n, int k)
{
    queue<int> q;
    vector<int> result;
    for (int i = 1; i <= n; i++) { // 큐에 N개의 원소 넣기
        q.push(i);
    }
    int cnt = 0; // 카운트 변수
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        cnt++;
        if (cnt == k) { // k번째 pop하는 원소라면
            result.push_back(x);
            cnt = 0;
            continue;
        }
        q.push(x); // pop한 원소 다시 push
    }
    return result;
}

int main()
{
    int n, k;
    vector<int> v;
    // 입력
    cin >> n >> k;
    // 연산
    v = josephusProb(n, k);
    // 출력
    cout << "<";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i != v.size() - 1) {
            cout << ", ";
        }
    }
    cout << ">";
}
