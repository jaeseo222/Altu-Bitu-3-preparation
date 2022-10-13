#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//높이가 heigt이하인 지점이 물에 잠길때, (x,y)에서 상하좌우로 이동하며 visit벡터를 채우는 함수
void dfs(int x, int y, vector<vector<int>> graph, vector<vector<int>> visit, int height){

    int dx[4]={-1, 0, 1, 0};
    int dy[4]={0,-1,0,1};

    if(graph[x][y] <= height){
        visit[x][y] = 2;
    }

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        /*if (ny < 0 || nx < 0 || ny >=  || nx >= N)
            continue;
        if (map[ny][nx] && !visited[ny][nx]) {
            visited[ny][nx] = true;
            DFS(ny, nx);
        }*/
    }
}

int main(){
    //입력
    int n;
    cin >>n;

    vector<vector<int>> graph(n, vector<int>(n,0)); //지역들의 높이 정보
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> graph[i][j];
        }
    }

    int max_num = 0; //물에 잠기지 않는 영역의 최대 개수
    //0: 방문x 1: 방문 2: 물에 잠김
    vector<vector<int>> visit(n, vector<int>(n,0));

}
