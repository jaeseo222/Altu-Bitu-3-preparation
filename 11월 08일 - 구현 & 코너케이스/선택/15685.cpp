#include<iostream>
#include<vector>
using namespace std;

int dy[4] = {0, -1, 0, 1}; //순서대로 이동방향 0,1,2,3
int dx[4] = {1, 0, -1, 0};

//map벡터와 direction벡터에 드래곤커브의 좌표와 방향 표시하는 함수
void dragonCurve(int& y, int& x, vector<vector<int>>& map, vector<int>& dir){
    //다음 세대로 넘어갈 때 이전 세대의 각 이동방향에 +1한 뒤, 뒤집어서 추가해 준다(그림참고)
    for (int i = dir.size()-1; i >= 0; i--){
        int nd = (dir[i] + 1) % 4; //1 더해주기
        y += dy[nd];
        x += dx[nd];
        map[y][x] = 1;
        dir.push_back(nd);
    }
}

//네 꼭지점이 모두 드래곤커브의 일부인 정사각형 카운트하는 함수
int cntSquare(vector<vector<int>>& board){
    int cnt=0; //정사각형 개수

    for (int j = 0; j < 100; j++){
        for (int i = 0; i < 100; i++){
            if (board[j][i] == 1 && board[j][i + 1] == 1 && board[j + 1][i] == 1 && board[j + 1][i + 1] == 1) {
                cnt++;
            }
        }
    }
    return cnt;
}


int main(){
    int n;
    int x,y,d,g;
    cin >> n;
    vector<vector<int>> board(101, vector<int>(101, 0)); //드래곤커브 꼭지점의 좌표 저장하는 벡터

    while (n--){
        cin >> x >> y >> d >> g;
        vector<int> dir; //드래곤커브의 방향(0,1,2,3) 저장하는 벡터

        //0세대 드래곤커브
        board[y][x] = 1;
        y += dy[d];
        x += dx[d];
        board[y][x] = 1;
        dir.push_back(d);

        //1세대부터 g세대까지의 드래곤커브
        while (g--){
            dragonCurve(y, x, board, dir);
        }
    }

    //정사각형 개수 세기
    cout << cntSquare(board) << '\n';

    return 0;
}