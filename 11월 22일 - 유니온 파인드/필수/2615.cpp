#include<iostream>
#include<vector>
using namespace std;
#define N 19

int board[20][20];

bool check(int y, int x, int dy, int dx) {
	//가려는 반대 방향의 색깔이 같다면 이미 체크한 것이므로 패스
	int nx = x - dx; int ny = y - dy;
	if (0 < ny <= 20 && 0 < nx <= 20) {
		if (board[y][x] == board[ny][nx]) {
			return false;
		}
	}
	//5개 연속인지 확인
	nx = x; ny = y;
	for (int d = 0; d < 4; d++) {
		nx += dx;	ny += dy;
		if (0 < ny <= 20 && 0 < nx <= 20) {
			if (board[y][x] != board[ny][nx]) {
				return false;
			}
		}
	}
	//6개 이상 연속인 경우
	nx += dx; ny += dy;
	if (0 < ny <= 20 && 0 < nx <= 20) {
		if (board[y][x] == board[ny][nx]) {
			return false;
		}
	}
	return true;
}

bool checkFive(int idx1, int idx2) {
	//오른쪽
	if (check(idx1, idx2, 0, 1)) {
		return true;
	}
	//아래
	if (check(idx1, idx2, 1, 0)) {
		return true;
	}
	//오른쪽아래 대각선
	if (check(idx1, idx2, 1, 1)) {
		return true;
	}
	//오른쪽 위 대각선
	if (check(idx1, idx2, -1, 1)) {
		return true;
	}
	return false;
}

int main() {
	bool res;
	//입력
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> board[i][j];
		}
	}
	//오목 체크 - 왼쪽 위부터 체크한다 (출력조건 때문)
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (board[i][j]) {
				res = checkFive(i, j);
				if (res) {
					//승부 결정된 경우
					cout << board[i][j] << '\n';
					cout << i << ' ' << j << '\n';
					return 0;
				}
			}
		}
	}
	//승부가 결정되지 않은 경우
	cout << "0";

}
