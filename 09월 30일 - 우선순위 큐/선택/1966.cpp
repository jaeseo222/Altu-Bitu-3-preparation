#include <iostream>
#include <queue>

using namespace std;

//주어진 조건에 맞게 인쇄한 수를 카운드 하는 함수
int print(int m, queue<pair<int, int>> list, priority_queue<int> pq) {
    int cnt = 0;

    while (!list.empty()) {
        //나머지 문서들 중에 출력하려는 문서의 중요도보다 높은 문서가 있는지 체크
        if (list.front().second < pq.top()) {  //높은 문서가 있다 -> list 뒤로 보내기
            list.push(list.front());
            list.pop();
            continue;
        }

        //출력
        cnt++;
        if (list.front().first == m) {  //우리가 구해야 하는 문서
            break;
        }
        list.pop();
        pq.pop();

    }
    return cnt;
}

int main() {

    int t;
    //입력
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        queue<pair<int, int>> list;
        priority_queue<int> pq; //우선순위 큐, 중요도 저장

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            list.push({i, x});
            pq.push(x);
        }

        //연산, 출력
        cout << print(m, list, pq) << '\n';
    }


    return 0;
}