#include <iostream>
#include <vector>
#include <map>

using namespace std;
const int MAX = 2e5; //친구 관계가 모두 다른 이름으로 들어왔을 때 정점의 최댓값 : 1e5*2

vector<int> parent(MAX+1,-1);
map<string, int> people;

int findParent(int node) {
	if (parent[node] < 0) {
		return node;
	}
	return parent[node] = findParent(parent[node]);
}

void unionInput(int x, int y) {
	int xp = findParent(x);
	int yp = findParent(y);

	if (xp == yp) {
		return;
	}
	if (parent[xp] < parent[yp]) {
		parent[xp] += parent[yp];
		parent[yp] = xp;
	}
	else {
		parent[yp] += parent[xp];
		parent[xp] = yp;
	}
}
/*
* 1. 어떤 집합(친구 네트워크)에 원소가 몇 개 있는지 판단
*    -> weighted union find
     -> 루트 정점에 원소의 개수 저장
  2. 보통 정점이 숫자였기에 vector의 인덱스로 표현했고 함수도 인덱스를 이용해서 구현했다!
     -> But, 이 문제는 정점이 이름 즉 문자열로 들어옴
	 -> 기존 함수를 이용하기 위해서 문자열인 정점과 인덱스를 매핑해주자!
*/
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, f;
	string a, b;

	cin >> t;
	while (t--) {
		//케이스마다 인덱스와 맵 초기화
		int idx = 1;
		parent.assign(MAX+1, -1);

		cin >> f;
		whlie(f--){
			cin >> a >> b;
			if (!people[a]) {
				people[a] = idx++;
			}
			if (!people[b]) {
				people[b] = idx++;
			}

			unionInput(people[a], people[b]);

			cout << -parent[findParent(people[a])]<<'\n';
		}

	}
	return 0;
}
