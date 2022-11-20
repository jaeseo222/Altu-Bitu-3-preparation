#include <iostream>
#include <vector>

using namespace std;

vector<int> subtree_cnt;

int treeDp(int cur, vector<vector<int>>& graph) {
    if (subtree_cnt[cur] != -1) { // 이미 탐색한 노드
        return subtree_cnt[cur];
    }

    // 서브트리에 속한 정점의 수를 세고, 저장
    subtree_cnt[cur] = 0;
    int node = 1;
    for (int i = 0; i < graph[cur].size(); i++) {
        node += treeDp(graph[cur][i], graph);
    }
    return subtree_cnt[cur] = node;
}

/*
 * 트리의 정점의 수 구하기 응용 문제
 *
 * 1. 루트에서 DFS를 사용하여 탐색
 * 2. 각 노드를 루트로 하는 서브트리의 정점 수를 재귀적으로 배열에 저장
 * - 서브트리에 속한 정점의 개수를 저장하는 dp 배열을 -1로 초기화
 * - 탐색 시 현재 정점의 dp 값을 0으로 설정함으로써 자식 노드만 탐색(부모 노드는 0이 저장되어 있으므로 탐색하지 않음)
 * 3. 쿼리로 주어지는 정점의 서브트리의 정점의 개수를 dp에서 찾아서 출력
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, r, q, u, v, input;

    // 입력
    cin >> n >> r >> q;
    vector<vector<int>> graph(n + 1, vector<int>(0));
    subtree_cnt.assign(n + 1, -1);
    while (--n) { // 무방향 그래프
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // 연산
    treeDp(r, graph);

    // 출력
    while (q--) {
        cin >> input;
        cout << subtree_cnt[input] << '\n';
    }
    return 0;
}
