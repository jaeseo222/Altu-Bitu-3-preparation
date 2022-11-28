#include<iostream>
#include<vector>
#include<queue>

using namespace std;
typedef pair<int, int> pi;
const int INF = 1e6 + 1;

long long prim(int n, vector<vector<pi>>& graph, int start) {
	priority_queue<pi, vector<pi>, greater<>> pq;
	vector<int> cost(n + 1, INF); //cost
	vector<bool>visit(n + 1, false); //방문 check
	int cnt = 0; //visit한 정점 수
	long long sum = 0;

	//초기화
	cost[start] = 0;
	pq.push({ 0, start });

	while (!pq.empty()) {
		int weight = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (visit[cur]) {
			continue;
		}
		visit[cur] = true;
		cnt++;
		sum += weight;

		for (auto [next_w, next] : graph[cur]) {
			if (!visit[next] && (cost[next] > next_w)) {
				cost[next] = next_w;
				pq.push({ next_w, next });
			}
		}

	}
	if (cnt != n) {
		return -1;
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

	while (m--) {
		cin >> a >> b >> c;
		graph[a].push_back({ c, b });
		graph[b].push_back({ c, a });
		price += c;
	}

	long long result = prim(n, graph, 1);
	//절약한 금액 계산이므로 price에서 MST비용 빼주기
	printf("%lld", result == -1 ? -1 : price - result);
}