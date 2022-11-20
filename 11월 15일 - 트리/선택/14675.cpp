#include <iostream>
#include <vector>

using namespace std;


//단절점, 단절선 파악 함수
string check(int t, int k, vector<vector<int>>& tree) {
	if (t == 2) {
		return "yes";
	}
		
	if (tree[k].size() >= 2) {
		return "yes";
	}
		
	return "no";
}

/**
 * 부모 노드를 알 수 없기에 트리를 양방향 그래프로 저장
 * 단절점: 트리는 모든 정점이 연결되어 있고, 싸이클이 존재하지 않기 때문에 연결된 간선이 2개 이상이면 단절점
 * 단절선: 트리는 모든 정점이 연결되어 있고, 싸이클이 존재하지 않기 때문에 모든 간선이 단절선
 */

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, v, u, test_case;
	cin >> n;

	vector<vector<int>> tree (n + 1, vector<int>(0));

	n--;
	while (n--) {
		cin >> v >> u; // 무방향 그래프
		tree[v].push_back(u);
		tree[u].push_back(v);
	}

	cin >> test_case;

	int t, k;
	while (test_case--) {
		cin >> t >> k;
		cout << check(t, k, tree) << '\n';
						
	}
}
