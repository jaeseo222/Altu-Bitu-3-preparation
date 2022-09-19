#include <iostream>
#include <vector>

using namespace std;
const int MAX = 3000;


vector<vector<int>> board;
vector<vector<bool>> check;
int dr[5] = { 0, -1, 1, 0, 0 };
int dc[5] = { 0, 0, 0, -1, 1 };
int ans = MAX;

int chkFlower(int r, int c) {
  
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (check[nr][nc]) { // 이미 꽃 있다면
            return -1;
        }
        sum += board[nr][nc];
    }
    return sum;
}
void plant(int r, int c, bool marking_type) { //상하좌우로 꽃 심거나 돌려놓기.


    for (int i = 0; i < 5; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        check[nr][nc] = marking_type;
    }

}
void minFlower(int cnt, int sum) {

    if (cnt == 3) {
        ans = min(ans, sum);
        return;
    }
    for (int i = 1; i < board.size()-1; i++) {
        for (int j = 1; j < board.size() - 1; j++) {
            int sumFlower = chkFlower(i, j);
            if (sumFlower == -1) {
                continue;
            }
            plant(i, j, 1); 
            minFlower(cnt + 1, sum + sumFlower);
            plant(i, j, 0);
        }
    }
}

int main() {

    int n; 

    // 입력
    cin >> n;

    board.assign(n, vector<int>(n, 0));
    check.assign(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    // 연산 & 출력
    minFlower(0, 0);

    cout << ans;
    return 0;
}
