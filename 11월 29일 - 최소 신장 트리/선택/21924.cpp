#include<iostream>
#include<vector>
#include<queue>

using namespace std;
typedef pair<int, int> pi;
const int INF =1e6+1;

long long prim(int n,vector<vector<pi>> graph) {
	priority_queue<pi> pq;
	vector<int> cost(n + 1, INF); //cost
	vector<bool>visit(n + 1, false); //방문 check

	long long sum=0;
	//초기화
	cost[1] = 0;
	pq.push(pi(0, 1));

	while (!pq.empty()) {
		
		int cur = pq.top().second;
		pq.pop();

		if (visit[cur]) {
			continue;
		}
		visit[cur] = true;
		
		for (auto i : graph[cur]) {
			if (!visit[i.second] && (cost[i.second] > i.first)) {
				cost[i.second] = i.first;
				pq.push(make_pair(-cost[i.second], i.second));
			}
		}

	}
	for (int i = 1; i <= n; i++) {
		if (cost[i] == INF) {
			return -1;
		}
		sum += cost[i];
	}
	return sum;
}

/*
절약한 비용을 구해야하므로 처음에 총 비용 구해야함
pair 쌍 만들어서 graph에 삽입 후 prim으로 MST 간선 합 구하기
*/


int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<pi>> graph = vector<vector<pi>>(n + 1);

	int a, b, c;
	long long price = 0;

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(c, b));
		graph[b].push_back(make_pair(c,a));
		price += c;
	}
	
	long long result = prim(n, graph);
	//절약한 금액 계산이므로 price에서 MST비용 빼주기
	printf("%lld", result == -1 ? -1 :price- result);
}