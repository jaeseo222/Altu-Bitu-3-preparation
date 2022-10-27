#include<iostream>
#include<queue>
#include<vector>
#define INF 987654321

using namespace std;

typedef pair<int, int> pii;
vector<pii> graph[801];
int n;

int dijkstra(int start, int end) {
	vector<int> dist (n+ 1, INF);
	dist[start] = 0;
	//pq 선언
	priority_queue < pii, vector<pii>, greater<pii>> pq;
	pq.push(pii(0, start));

	//dijstra
	while (!pq.empty()) {
		int d = pq.top().first;
		int v = pq.top().second;
		pq.pop();

		if (d > dist[v]) {
			continue;
		}
		
		//탐색 & 거리 값 갱신
		for (int i = 0; i <graph[v].size(); i++) {
			int nxt_v = graph[v][i].first;
			int cost = graph[v][i].second;
			//거리가 작으면 갱신 후 pq에 삽입
			if (dist[nxt_v] > dist[v] + cost) {
				dist[nxt_v] = dist[v] + cost;
				pq.push(pii(dist[nxt_v], nxt_v));
			}
		}
	}
	return dist[end];
}

/*
필수적으로 지나야 하는 v1,v2 노드를 지나가는 방법
1) 1->v1->v2->n
2) 1->v2->v1->n
두 가지 경로에 대해 다익스트라 진행 후 min 값 선택
*/
int solve(int v1,int v2) {
	int r1, r2;
	//1->v1->v2->n
	int sv1 = dijkstra(1, v1);
	int v1v2 = dijkstra(v1, v2);
	int v2n = dijkstra(v2, n);
	if (sv1 == INF|| v1v2 == INF ||v2n == INF) {
		r1 = INF;
	}
	else {
		r1 = sv1 + v1v2 + v2n;
	}

	//1->v2->v1->n
	int sv2 = dijkstra(1, v2);
	int v2v1 = dijkstra(v2, v1);
	int v1n = dijkstra(v1, n);
	if (sv2 == INF || v2v1 == INF || v1n == INF) {
		r2 = INF;
	}
	else {
		r2 = sv2+v2v1 + v1n;
	}
	//둘 다 INF면 경로 X
	if (r1 == INF && r2 == INF) {
		return -1;
	}
	return min(r1, r2);	
}

int main() {
	int  e, v1, v2;

	cin >> n >> e;
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		//입력받은 값 저장. 양방향 그래프이므로 a와 b 모두 저장 해주어야함
		graph[a].push_back(pii(b, c));
		graph[b].push_back(pii(a, c));
	}

	cin >> v1 >> v2;
	cout<<solve(v1,v2);
}