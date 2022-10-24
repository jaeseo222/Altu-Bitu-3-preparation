#include<iostream>
#include<memory.h>
#include<algorithm>
using namespace std;

const int MAX = 100;
int board[MAX][MAX]={0,}; //지역들의 높이 정보 저장
bool visit[MAX][MAX]={false,}; //방문 여부 저장

//높이가 heigt이하인 지점이 물에 잠길때의 dfs함수
void dfs(int x, int y, int height, int n){
    int dx[4]={-1, 0, 1, 0};
    int dy[4]={0,-1,0,1};

    visit[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i]; //상하좌우로 이동 후의 좌표
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= n || ny >= n) { //board영역 밖에 있을때
            continue;
        }

        if(!visit[nx][ny] && board[nx][ny]>height){ //방문 안했고+물에 안 잠겼으면 방문해준다
            dfs(nx, ny, height, n);
        }
    }
}

int main(){
    //입력
    int n;
    cin >>n;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> board[i][j];
        }
    }

    //연산
    int max_cnt = 1; //물에 잠기지 않는 영역의 최대 개수
    for(int height=1; height<=MAX; height++){ //잠기는 높이를 변화시킨다
        memset(visit,false,sizeof(visit)); //visit배열 초기화

        int cnt=0; //물에 잠기지 않는 영역의 개수
        for(int i=0;i<n;i++){ //각 지역을 돌며 방문,영역의 개수 카운트
            for(int j=0;j<n;j++){
                if(!visit[i][j] && board[i][j]>height){
                    dfs(i,j,height,n);
                    cnt++;
                }
            }
        }
        max_cnt = max(max_cnt, cnt);
    }

    //출력
    cout<<max_cnt<<'\n';
    return 0;
}
