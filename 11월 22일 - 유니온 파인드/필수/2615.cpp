#include<iostream>
#include<vector>
using namespace std;
const int SIZE = 19;
typedef vector<vector<int>> vi;

/**
 * [오목]
 *
 * 1. 특정 좌표(r, c)를 가장 왼쪽으로 하는 가능한 모든 오목 배치에 대해 오목 여부 확인
 *    가능한 모든 배치 :  오른쪽, 아래, 우하향, 우상향
 * 2. 육목이상이 되는지 확인해야 함
 */

bool checkValid(int ny, int nx) {
	return (0 < ny && ny <= SIZE && 0 < nx && nx <= SIZE);
}


bool check(int y, int x, int dy, int dx, vi &board) {
	//가려는 반대 방향의 색깔이 같다면 이미 체크한 것이므로 패스
	int nx = x - dx; int ny = y - dy;
	if (checkValid(ny, nx)){
		if (board[y][x] == board[ny][nx]) {
			return false;
		}
	}

	//연속인 개수 확인 -> 6개 이상이면 X
	int cnt = 1;
	nx = x; ny = y;
	while (cnt < 7) {
		nx += dx;	ny += dy;
		if (checkValid(ny, nx))
		{
			if (board[y][x] == board[ny][nx]) {
				cnt++;
			}
		}
	}
	if (cnt > 5) {
		return false;
	}
	return true;
}

bool checkDir(int idx1, int idx2, vi &board) {
	//오른쪽, 아래, 오른쪽아래 대각선, 오른쪽위 대각선
	int dr[4] = { 0, 1, 1, -1 };
	int dc[4] = { 1, 0, 1, 1 };

	for (int i = 0; i < 4; i++) {
		if (check(idx1, idx2, dr[i], dc[i], board)) {
			return true;
		}
	}
	return false;
}

int main() {
	bool res;
	vi board(SIZE + 1, vector<int>(SIZE+1, 0));
	//입력
	for (int i = 1; i <= SIZE; i++) {
		for (int j = 1; j <= SIZE; j++) {
			cin >> board[i][j];
		}
	}
	//오목 체크 - 왼쪽 위부터 체크한다 (출력조건 때문)
	for (int i = 1; i <= SIZE; i++) {
		for (int j = 1; j <= SIZE; j++) {
			if (!board[i][j]) {
				continue;
			}
			res = checkDir(i, j, board);
			if (res) {
				//승부 결정된 경우
				cout << board[i][j] << '\n';
				cout << i << ' ' << j << '\n';
				return 0;
			}
		}
	}
	//승부가 결정되지 않은 경우
	cout << "0";
	return 0;
}
