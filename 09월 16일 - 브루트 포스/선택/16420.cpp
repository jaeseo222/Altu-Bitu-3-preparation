#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;

typedef pair<int, int> ci;

int dx[5] = { 0,0,0,-1,1 };
int dy[5] = { 0,1,-1,0,0 };
vector<vector<bool>> board; 
vector<vector<int>> cost;
int min_cost= INF;

bool check(int x, int y) { //꽃을 심을 수 있는지 확인

	
	for (int i = 0; i < 5; i++) {
	
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (board[nx][ny]) //무언가 이미 심어져 있다면
			return false;
	}

	return true;
	
}
void plant(int x,int y,bool marking_type) { //상하좌우로 꽃 심거나 돌려놓기.


	for (int i = 0; i < 5; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		board[nx][ny] = marking_type;
	}

}


void dfs(int cnt) { //cnt : 꽃을 몇개 심었는지

	if (cnt == 3) {
		int total = 0;

		// 꽃이 심어진 영역의 비용 계산하기
		for (int i = 0; i < board.size() ; i++) {
			for (int j = 0; j < board.size(); j++) {

				if (board[i][j])

					total += cost[i][j];
			}

		}

		min_cost = min(min_cost, total);
		return;
	}

	// 꽃 심을 위치 정하기
	for (int i = 1; i < board.size() - 1; i++) {
		for (int j = 1; j < board.size() - 1; j++) {

			if (check(i, j)) { // 꽃을 심을 수 있다면
				plant(i, j, 1); 
				dfs(cnt + 1); 
				plant(i, j, 0); // 원상복구

			}
		}
	}

}
int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	cost.assign(n, vector<int>(n, 0));
	board.assign(n, vector<bool>(n, false));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> cost[i][j];
		}
	}

	dfs(0);
	cout << min_cost;

}
