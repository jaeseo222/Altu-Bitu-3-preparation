#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int x, int y, int n, int m, vector<vector<bool>> &board) {
	int dx[4] = { 0,1,0,-1 };
	int dy[4] = { 1,0,-1,0 };

	queue<pair<int, int>> q;
	q.push(make_pair(x,y ));
	board[x][y] = false;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
				continue;
			}
			if (board[nx][ny]) {
				board[nx][ny] = false;
				q.push(make_pair( nx, ny ));
			}
			
		}
	}
}

int main(void) {

	int t, m, n, k, x, y, cnt;
	

	cin >> t;
	while (t--) {

		cin >> m >> n >> k;

		vector<vector<bool>> board(n, vector<bool>(m, false));
		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			board[y][x] = true;
		}

		cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j]) {
					cnt++;
					bfs(i, j, n, m, board);
				}
			}
		}
		
		cout << cnt << '\n';
	}
	return 0;
}
