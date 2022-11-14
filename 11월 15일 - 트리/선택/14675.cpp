#include <iostream>
#include <vector>

using namespace std;

/*
단절점 : 연결된 간선이 2개이상
단절선 : 모든 선이 단절선. ( cycle이 없기 때문)
*/

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<vector<int>> tree;
	

	int n,v,u,test_case; 
	cin >> n;

	tree.assign(n + 1, vector<int>(0));
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

		if (t == 1) { //단절점체크
			if (tree[k].size() >= 2)
				cout << "yes\n";
			else
				cout << "no\n";
		}
		else if (t == 2) // 단절선체크
			cout << "yes\n";
	}
}
