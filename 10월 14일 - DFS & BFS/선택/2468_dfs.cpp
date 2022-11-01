#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector<vector<int>> board;
vector<vector<bool>> visit;

//높이가 heigt이하인 지점이 물에 잠길때의 dfs함수
void dfs(int r, int c, int& height) {
    int dr[4] = { -1, 0, 1, 0 };
    int dc[4] = { 0, -1, 0, 1 };
    visit[r][c] = true;

    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i]; //상하좌우로 이동 후의 좌표
        int nc = c + dc[i];

        if (nr < 0 || nc < 0 || nr >= n || nc >= n) { //board영역 밖에 있을때
            continue;
        }

        if (!visit[nr][nc] && board[nr][nc] > height) { //방문 안했고+물에 안 잠겼으면 방문해준다
            dfs(nr, nc, height);
        }
    }
}

//물에 잠기지 않는 영역의 최대 개수를 계산하는 함수
int countArea(int max_height) {
    int max_cnt = 1; //물에 잠기지 않는 영역의 최대 개수

    for (int height = 1; height <= max_height - 1; height++) { //잠기는 높이를 변화시킨다
        visit.assign(n, vector<bool>(n, false)); //방문 여부 저장

        int cnt = 0; //물에 잠기지 않는 영역의 개수
        for (int i = 0; i < n; i++) { //각 지역을 돌며 방문,영역의 개수 카운트
            for (int j = 0; j < n; j++) {
                if (!visit[i][j] && board[i][j] > height) {
                    dfs(i, j, height); //dfs
                    cnt++;
                }
            }
        }
        max_cnt = max(max_cnt, cnt);
    }

    return max_cnt;
}

int main() {
    //입력
    cin >> n;

    board.assign(n, vector<int>(n, 0)); //지역들의 높이 정보 저장
    int max_height = 0; //높이의 최대값
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            max_height = max(board[i][j], max_height);
        }
    }

    //연산, 출력
    cout << countArea(max_height) << '\n';
    return 0;
}