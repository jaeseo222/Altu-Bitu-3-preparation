#include <iostream>
#include <queue>
#include <vector>
using namespace std;

//위상 정렬 함수
vector<int> topologicalSort(int n, vector<int> &indegree, vector<vector<int>> &graph) {
    queue<int> q;
    vector<int> order; //가수들 순서
    for (int i = 1; i <= n; i++) {
        if (!indegree[i]) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        order.push_back(cur);
        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i];
            indegree[next]--;
            if (!indegree[next]) {
                q.push(next);
            }
        }
    }

    if (order.size() != n) { //사이클이 존재하는 경우: 0 출력
        order.clear();
        order.push_back(0);
    }
    return order;
}

int main(void) {
    //입력
    int n, m; //가수, PD수
    cin >> n >> m;

    vector<int> indegree(n + 1, 0);
    vector<vector<int>> graph(n + 1, vector<int>(0));
    while (m--) {
        int num; //각 PD가 담당한 가수의 수
        int singer1; //가수 번호
        cin >> num;
        cin >> singer1;

        for(int i=0; i<num-1; i++) {
            int singer2;
            cin >> singer2;
            graph[singer1].push_back(singer2);
            indegree[singer2]++;
            singer1 = singer2;
        }
    }

    //연산
    vector<int> ans = topologicalSort(n, indegree, graph);

    //출력
    for(int i=0; i<ans.size(); i++){
        cout<< ans[i]<<'\n';
    }
    return 0;
}