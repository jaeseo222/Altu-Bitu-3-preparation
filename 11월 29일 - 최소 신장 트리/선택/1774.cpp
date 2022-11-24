#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cmath>

using namespace std;

typedef tuple<double, int, int> tp;
typedef pair<double, double> ci;

vector<int> parent;

// Find 연산
int findParent(int x) {
	if (parent[x] < 0) {
		return x;
	}
	return parent[x] = findParent(parent[x]);
}

// Union 연산
bool unionNodes(int x, int y) {
	int px = findParent(x);
	int py = findParent(y);

	if (px == py) {
		return false;
	}

	if (parent[px] < parent[py]) {
		parent[px] += parent[py];
		parent[py] = px;
	}
	else {
		parent[py] += parent[px];
		parent[px] = py;
	}
	return true;
}

double kruskal(int v, vector<tp>& edge) {
	double sum = 0;
	int cnt = 0;
	
	for (int i = 0; i < edge.size(); i++) {
		double w = get<0>(edge[i]);
		int x = get<1>(edge[i]);
		int y = get<2>(edge[i]);

		if (!unionNodes(x, y)) {
			continue;
		}
		sum += w;
		cnt++;

		if (cnt == v - 1) {
			return sum;
		}
	}
	return 0;
}

/*
* 이미 연결된 정점이 있을 때 거리가 최소가 되도록 간선 추가 연결하기
* 1. 우주신 사이의 거리 계산 (간선의 weight)
* 2. 이미 연결된 통로를 추가 (유니온으로 사이클이 생기는지 확인)
* 3. 간선을 오름차순으로 정렬
* 4. 크루스칼로 간선을 추가 연결
*/

int main()
{
	int n, m, a, b, v = 0;

	// 입력
	cin >> n >> m;
	vector<tp> edge;
	parent.assign(n + 1, -1);
	// 좌표
	vector<ci> gods(n + 1);
	for (int i = 1; i <= n; i++) { 
		cin >> gods[i].first >> gods[i].second;
	}

	// 우주신 사이의 거리 계산
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			double dx = gods[i].first - gods[j].first;
			double dy = gods[i].second - gods[j].second;
			edge.push_back({ sqrt(dx * dx + dy * dy), i, j });
		}
	}

	// 이미 연결된 통로를 추가
	while (m--) {
		cin >> a >> b;
		if (unionNodes(a, b)) {
			v++;
		}
	}
	sort(edge.begin(), edge.end());

	// 연산 & 출력
	cout << fixed;
	cout.precision(2);
	cout << kruskal(n - v, edge);
	return 0;
}
