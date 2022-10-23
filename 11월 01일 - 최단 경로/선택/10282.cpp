#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;
const int INF = 1e7; // 지나는 최대 간선의 개수(n - 1) * 간선 가중치의 최대값 (1e4 * 1e3)

/*
* 기본 다익스트라 문제
* 의존성: 방향 그래프 (a가 b에 의존: b -> a (감염의 방향))
* 총 감염되는 컴퓨터의 수: 도달 가능한 모든 노드의 수
* 마지막 컴퓨터가 감염되기까지 걸리는 시간: 마지막으로 연결되는 노드까지 최단 거리(시간)
*/

ci dijkstra(int vertex, int start, vector<vector<ci>>& graph) {
    vector<int> dist(vertex + 1, INF);
    priority_queue<ci, vector<ci>, greater<>> pq; //first : 시작점으로부터의 거리, second : 정점

    dist[start] = 0;
    pq.push({ 0, start });
    int cnt = 0, time = 0;
    while (!pq.empty()) {
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if (weight > dist[node]) //이미 확인했던 정점
            continue;
        cnt++; // 감염된 컴퓨터 증가
        time = weight; // 마지막으로 감염되는 컴퓨터까지의 최단 거리(시간)
        for (int i = 0; i < graph[node].size(); i++) {
            int next_node = graph[node][i].first;
            int next_weight = weight + graph[node][i].second;
            if (dist[next_node] > next_weight) { //더 짧은 경로로 갈 수 있는 경우
                dist[next_node] = next_weight;
                pq.push({ next_weight, next_node });
            }
        }
    }
    return {cnt, time};
}

int main() {
    int t, n, d, c, a, b, s;

    //입력
    cin >> t; // 테스크 케이스의 개수
    while (t--) {
        cin >> n >> d >> c;
        vector<vector<ci>> graph(n + 1, vector<ci>(0)); //인접 리스트
        while (d--) {
            cin >> a >> b >> s;
            graph[b].emplace_back(a, s); //방향 그래프 ( b -> a )
        }
        //연산
        ci ans = dijkstra(n, c, graph);
        //출력
        cout << ans.first << ' ' << ans.second << '\n';
    }
 }
