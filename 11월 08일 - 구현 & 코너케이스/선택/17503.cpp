#include <iostream>
#include <vector>
#include <stack>

using namespace std;



int n, m;
int simulate(vector<vector<int>> board,int r,int c,int d) {

	// 북 동 남 서 
	int dr[4] = { -1,0,1,0, };
	int dc[4] = { 0,1 ,0, -1,};

	int ans = 0; // 청소하는 칸의 개수
	

	while (true) {

		if (board[r][c] == 0) {
			board[r][c] = 2; //현재 위치 청소
			ans++;
		}
	
		int step;
		//왼쪽 방향에 아직 청소하지 않은 공간이 남아있는지
		for ( step = 0; step < 4; step++) {
	
			d = (d + 3) % 4;//현재 방향의 왼쪽 좌표
			int nr = r + dr[d];
			int nc = c + dc[d];
	
			if (!board[nr][nc]) { // 청소되지 않은 곳이라면
				// 그 방향으로 회전하고 한칸을 전진
				r = nr;
				c = nc; 
				break; // 다시 1번부터 시작
			}

		}

		if (step == 4) { //네 방향 모두 벽이거나 청소가 되어있는 경우

			//바라 보는 방향을 유지한채로 한 칸 후진
			int br = r - dr[d]; 
			int bc = c - dc[d]; 
			
			if (board[br][bc] == 1) { //뒤쪽 방향이 벽인 경우 작동 멈춤 
				break;
			}

			//후진
			r = br;
			c = bc;
		}
	
	}
	
	return ans;

}
int main() {

	int r, c, d;

	cin >> n >> m >> r >> c >> d;

	vector<vector<int>> board(n, vector<int>(m, 0));

	//입력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	cout << simulate(board,r,c,d);

}
